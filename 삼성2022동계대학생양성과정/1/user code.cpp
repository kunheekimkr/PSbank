#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

typedef struct order
{
    int mNumber;   //주문 번호
    int mQuantity; //주문의 개수
    int mPrice;    //주문 가격
} order;

vector<vector<order>> temp(2);
vector<vector<vector<order>>> order_list(6, temp);
// n 번 주식에 대한 매수 주문은 order_list[n][0]에, 매도 주문은 order_list[n][1]에 저장

typedef struct deal
{
    int min;
    int max_price;
} deal;

vector<deal> deal_list(6);

vector<int> stock;
vector<int> isbuy;
vector<int> price;
vector<bool> erased;

bool compare_buy(order a, order b);                           //매수 주문을 정렬하기 위해 사용되는 함수
bool compare_sell(order a, order b);                          //매도 주문을 정렬하기 위해 사용되는 함수
void init();                                                  // Vector 초기화
int buy(int mNumber, int mStock, int mQuantity, int mPrice);  // 매수 주문
int sell(int mNumber, int mStock, int mQuantity, int mPrice); // 매도 주문
void cancel(int mNumber);                                     //주문 취소
int bestProfit(int mStock);                                   // 가능한 최대 거래 가격

bool compare_buy(order a, order b) //매수 주문을 정렬하기 위해 사용되는 함수
{
    if (a.mPrice == b.mPrice)
        return a.mNumber > b.mNumber; // 가격이 같을 때는 작은 번호의 주문이 앞으로

    else
        return a.mPrice < b.mPrice; // 더 높은 가격의 매수 주문이 앞으로
}

bool compare_sell(order a, order b) //매도 주문을 정렬하기 위해 사용되는 함수
{

    if (a.mPrice == b.mPrice)
        return a.mNumber > b.mNumber; // 가격이 같을 때는 작은 번호의 주문이 앞으로

    else
        return a.mPrice > b.mPrice; // 더 낮은 가격의 매수 주문이 앞으로
}

void init() // Vector 초기화
{
    for (int i = 1; i < 6; i++)
    {
        order_list[i][0].clear();
        order_list[i][1].clear();
        deal_list[i].max_price = 0;
        deal_list[i].min = 0;
    }
    stock.clear();
    stock.emplace_back(0);
    isbuy.clear();
    isbuy.emplace_back(0);
    price.clear();
    price.emplace_back(0);
    erased.clear();
    erased.push_back(true);
}

int buy(int mNumber, int mStock, int mQuantity, int mPrice) // 매수 주문
{
    stock.emplace_back(mStock);
    isbuy.emplace_back(0);
    price.emplace_back(mPrice);
    erased.push_back(false);

    for (int i = order_list[mStock][1].size() - 1; i >= 0; i--) // 매도 주문들을 탐색
    {

        if (order_list[mStock][1][i].mPrice > mPrice) // 매수 희망가보다 최소 매도 희망가가 높으면 반복문 탈출
            break;

        if (order_list[mStock][1][i].mQuantity > mQuantity) // 매수 희망 주식의 개수보다 최소 가격의 매도 희망 주식의 개수가 많으면 모두 매수 후 종료
        {
            int deal_price = order_list[mStock][1][i].mPrice;
            if (deal_list[mStock].min == 0)
                deal_list[mStock].min = deal_price;
            if (deal_price - deal_list[mStock].min > deal_list[mStock].max_price)
                deal_list[mStock].max_price = deal_price - deal_list[mStock].min;
            if (deal_price < deal_list[mStock].min)
                deal_list[mStock].min = deal_price;

            order_list[mStock][1][i].mQuantity -= mQuantity;
            while (order_list[mStock][1].back().mQuantity == 0)
            {
                erased[order_list[mStock][1].back().mNumber] = true;
                order_list[mStock][1].pop_back();
            }

            erased[mNumber] = true;
            return 0;
        }

        else // 매수 희망 주식의 개수보다 최소 가격의 매도 희망 주식의 개수가 적으면 매수 후 다음 최소 가격의 매도 주문 탐색
        {
            int deal_price = order_list[mStock][1][i].mPrice;
            if (deal_list[mStock].min == 0)
                deal_list[mStock].min = deal_price;
            if (deal_price - deal_list[mStock].min > deal_list[mStock].max_price)
                deal_list[mStock].max_price = deal_price - deal_list[mStock].min;
            if (deal_price < deal_list[mStock].min)
                deal_list[mStock].min = deal_price;

            mQuantity -= order_list[mStock][1][i].mQuantity;
            order_list[mStock][1][i].mQuantity = 0; // 거래 완료된 매도 주문을 취소 처리
            if (mQuantity == 0)                     // 매수 희망 주식의 개수 = 최소 가격의 매도 희망 주식의 개수 인 경우 모든 주문을 처리했으므로 종료
            {
                while (order_list[mStock][1].back().mQuantity == 0)
                {
                    erased[order_list[mStock][1].back().mNumber] = true;
                    order_list[mStock][1].pop_back();
                }
                erased[mNumber] = true;
                return 0;
            }
        }
    }
    if (order_list[mStock][1].size() > 0)
    {
        while (order_list[mStock][1].back().mQuantity == 0)
        {
            erased[order_list[mStock][1].back().mNumber] = true;
            order_list[mStock][1].pop_back();
        }
    }
    //남은 매수 주문 수량이 있다면 order_list[mStock][0] 에 넣은 후 벡터를 기준에 맞춰 정렬
    order buyord;
    buyord.mNumber = mNumber;
    buyord.mQuantity = mQuantity;
    buyord.mPrice = mPrice;
    order_list[mStock][0].emplace_back(buyord);
    for (int i = order_list[mStock][0].size() - 2; i >= 0; i--)
    {
        if (compare_buy(order_list[mStock][0][i], buyord))
        {
            order_list[mStock][0][i + 1] = buyord;
            break;
        }
        order_list[mStock][0][i + 1] = order_list[mStock][0][i];
        if (i == 0)
        {
            order_list[mStock][0][i] = buyord;
        }
    }

    return mQuantity;
}

int sell(int mNumber, int mStock, int mQuantity, int mPrice) // 매도 주문
{
    stock.emplace_back(mStock);
    isbuy.emplace_back(1);
    price.emplace_back(mPrice);
    erased.push_back(false);

    for (int i = order_list[mStock][0].size() - 1; i >= 0; i--) // 매수 주문들을 탐색
    {

        if (order_list[mStock][0][i].mPrice < mPrice) // 매도 희망가보다 최대 매수 희망가가 낮으면 반복문 탈출
            break;

        if (order_list[mStock][0][i].mQuantity > mQuantity) // 매도 희망 주식의 개수보다 최대 가격의 매수 희망 주식의 개수가 많으면 모두 매도 후 종료
        {
            int deal_price = order_list[mStock][0][i].mPrice;
            if (deal_list[mStock].min == 0)
                deal_list[mStock].min = deal_price;
            if (deal_price - deal_list[mStock].min > deal_list[mStock].max_price)
                deal_list[mStock].max_price = deal_price - deal_list[mStock].min;
            if (deal_price < deal_list[mStock].min)
                deal_list[mStock].min = deal_price;

            order_list[mStock][0][i].mQuantity -= mQuantity;
            while (order_list[mStock][0].back().mQuantity == 0)
            {
                erased[order_list[mStock][0].back().mNumber] = true;
                order_list[mStock][0].pop_back();
            }
            erased[mNumber] = true;
            return 0;
        }

        else // 매도 희망 주식의 개수보다 최대 가격의 매수 희망 주식의 개수가 적으면 매도 후 다음 최대 가격의 매수 주문 탐색
        {
            int deal_price = order_list[mStock][0][i].mPrice;
            if (deal_list[mStock].min == 0)
                deal_list[mStock].min = deal_price;
            if (deal_price - deal_list[mStock].min > deal_list[mStock].max_price)
                deal_list[mStock].max_price = deal_price - deal_list[mStock].min;
            if (deal_price < deal_list[mStock].min)
                deal_list[mStock].min = deal_price;

            mQuantity -= order_list[mStock][0][i].mQuantity;
            order_list[mStock][0][i].mQuantity = 0; // 거래 완료된 매수 주문을 취소 처리
            if (mQuantity == 0)                     // 매도 희망 주식의 개수 = 최대 가격의 매수 희망 주식의 개수 인 경우 모든 주문을 처리했으므로 종료
            {
                while (order_list[mStock][0].back().mQuantity == 0)
                {
                    erased[order_list[mStock][0].back().mNumber] = true;
                    order_list[mStock][0].pop_back();
                }
                erased[mNumber] = true;
                return 0;
            }
        }
    }
    if (order_list[mStock][0].size() > 0)
    {
        while (order_list[mStock][0].back().mQuantity == 0)
        {
            erased[order_list[mStock][0].back().mNumber] = true;
            order_list[mStock][0].pop_back();
        }
    }
    //남은 매도 주문 수량이 있다면 order_list[mStock][1] 에 넣은 후 벡터를 기준에 맞춰 정렬
    order sellord;
    sellord.mNumber = mNumber;
    sellord.mQuantity = mQuantity;
    sellord.mPrice = mPrice;
    order_list[mStock][1].emplace_back(sellord);

    for (int i = order_list[mStock][1].size() - 2; i >= 0; i--)
    {
        if (compare_sell(order_list[mStock][1][i], sellord))
        {
            order_list[mStock][1][i + 1] = sellord;
            break;
        }
        order_list[mStock][1][i + 1] = order_list[mStock][1][i];
        if (i == 0)
        {
            order_list[mStock][1][i] = sellord;
        }
    }

    return mQuantity;
}

void cancel(int mNumber) //주문 취소
{
    if (erased[mNumber])
        return;

    int mStock = stock[mNumber];
    int mBuy = isbuy[mNumber];
    int mPrice = price[mNumber];

    int low = 0;
    int high = order_list[mStock][mBuy].size();
    int mid;
    if (mBuy == 0)
    {
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (order_list[mStock][mBuy][mid].mPrice < mPrice)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    else
    {
        while (low <= high)
        {
            mid = (low + high) / 2;

            if (order_list[mStock][mBuy][mid].mPrice > mPrice)
                low = mid + 1;
            else
                high = mid - 1;
        }
    }

    while (order_list[mStock][mBuy][low].mPrice == mPrice)
    {
        if (order_list[mStock][mBuy][low].mNumber == mNumber)
        {
            erased[mNumber] = true;
            order_list[mStock][mBuy].erase(order_list[mStock][mBuy].begin() + low);
            break;
        }
        low++;
    }
}

int bestProfit(int mStock) // 가능한 최대 거래 가격
{
    return deal_list[mStock].max_price;
}