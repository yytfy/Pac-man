# Pac-man

## player
|name |type |description |
|---|---|---|
|direction|short|0=left, 1=right, 2=top, 3=buttom|
|speed|short||
|img||image of pacman|




## monster
|name |type |description |
|---|---|---|
|direction|short|0=left, 1=right, 2=top, 3=buttom|
|speed|short||
|img||image of pacman|


怪物逻辑
三种模式
追逐模式：
到路口搜索到目标的最短路径，每个幽灵有各自的目标
红(Blinky): 向吃豆人当前所在的点移动
粉(Pinky): 向吃豆人前方四格的位置移动
蓝(Lnky): 向与Blinky和吃豆人前方两格的线段再延长相同距离的位置移动
橙(Clyde): 若吃豆人附件八格范围内向左下角移动，否则向吃豆人当前所在点移动

追逐模式一段时间后进入分散模式

分散模式：
各自随机散开

分散模式一段时间后进入追逐模式

1. 每个路口随机选一个方向走
2. 如果在路口发现附近(6个移动格以内)有pacman则朝pacman走



## map
|name |type |description|
|---|---|---|
|blocks|block||
|monsters|monster||




