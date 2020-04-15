#include"Greedy.h"

// 122. 买卖股票的最佳时机 II
int maxProfit(vector<int>& prices) {
	// 增长相加 —— 中间增加的一定 >= 最高点-最低点
	// 贪心算法算法流程：
	// 遍历整个股票交易日价格列表 price，策略是所有上涨交易日都买卖（赚到所有利润），
	// 所有下降交易日都不买卖（永不亏钱）。
	// 设 tmp 为第 i - 1 日买入与第 i 日卖出赚取的利润，即 tmp = prices[i] - prices[i - 1] ；
	// 当该天利润为正 tmp > 0，则将利润加入总利润 profit；当利润为 00 或为负，则直接跳过；
	// 遍历完成后，返回总利润 profit。

	int total = 0;
	for (int i = 1; i < prices.size(); i++) {
		if (prices[i] > prices[i - 1]) total += prices[i] - prices[i - 1];
	}
	return total;
}