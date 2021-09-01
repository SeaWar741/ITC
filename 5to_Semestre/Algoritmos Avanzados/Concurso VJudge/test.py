import sys

coins = []
coinsValueTotal = 0
n = int(sys.stdin.readline())
inputs = sys.stdin.readline().split()
for i in range(len(inputs)):
    coin = int(inputs[i])
    coins.append(coin)
    coinsValueTotal += coin

coins.sort(reverse = True)
minCoins = 0

halfCoinsValueTotal = coinsValueTotal / 2

for i in range(len(coins)):
    minCoins +=  coins[i]
    if(minCoins > halfCoinsValueTotal):
        print(i+1)
        break