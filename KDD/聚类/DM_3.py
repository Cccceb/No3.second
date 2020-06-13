# -*- coding: utf-8 -*-
import numpy as np
import math
from scipy.cluster.hierarchy import dendrogram, linkage, fcluster
from matplotlib import pyplot as plt
import igraph

def calCosSimilarity(g):
    # 计算余弦相似度，返回相似度矩阵
    data = []
    for i in range(34):
        tmp = []
        sa = set(g.neighbors(i))
        for j in range(34):
            sb = set(g.neighbors(j))
            # 用两个点的邻居节点的交集/两个集合长度乘积的平方根
            tmp.append(len(sa & sb)/math.sqrt(len(sa)*len(sb)))
        data.append(tmp)
    return data
    # return 34- np.array(g.shortest_paths()) # 最短跳数，因为后面都是按相似度编程，所以用34-最短条数，等价于相似度
def Singlle(data,l1,l2):
    maxx = 0
    for i in l1:
        for j in l2:
            maxx = max(data[i][j],maxx)
    return maxx
def MAX(data,l1,l2):
    minn = 10000
    for i in l1:
        for j in l2:
            minn = min(data[i][j],minn)
    return minn
def AVG(data,l1,l2):
    sum = 0
    for i in l1:
        for j in l2:
            sum += data[i][j]
    return sum /(len(l1)*len(l2))
class myCluster:
    def __init__(self,data,g):
        self.data = data
        self.g = g
        self.m = g.ecount()
        self.x = []
        self.y = []
        self.kind = {}
    def cluster(self,fun=AVG):
        self.res = []
        def solve(kind,maxQ):
            skind = set(kind)
            real = 0
            null =0
            all = [0 for i in range(len(kind))]

            ############################ 计算模块化度量Q ####################
            for i in range(g.vcount()):
                for j in range(g.vcount()):
                    if i in g.neighbors(j) and kind[i] == kind[j]:
                            real += 1 # real每个簇内边的个数
            for i in range(g.vcount()):
                all[kind[i]] += g.degree(i)# all[i]表示标号为i的簇中节点的度的和
            for i in all:
                null += (i/(2*self.m))**2
            nowQ = (real/(2*self.m)) -null # 带入公式计算Q值
            num_kind = len(set(kind))
            print("Class：", num_kind, "Q：", nowQ)
            print(kind)
            self.kind[num_kind] = kind.copy() # 记录一些数据用于画图
            self.x.append(num_kind)
            self.y.append(nowQ)
            if len(skind) == 1: # 递归结束标志：当只剩下一个类的时候结束递归
                return maxQ
            if nowQ > maxQ:# 判断是否需要更新结果
                maxQ = nowQ
                self.res = kind.copy()
            maxx = -1
            tmpi,tmpj = -1,-1
            ############################ 选择相似度最大的两个簇进行合并 ####################################
            for i in range(g.vcount()):
                for j in range(g.vcount()):
                    # 如果两个点已经在同一个簇，或者不直接相连，那么可以先跳过
                    if i==j or kind[i] == kind[j] or j not in self.g.neighbors(i): continue
                    # 计算这两个簇之间的单链/全链/组平均相似度
                    tmp = fun(self.data,[x for x in range(g.vcount()) if kind[x] == kind[i]]
                              ,[x for x in range(g.vcount()) if kind[x] == kind[j]])
                    if tmp > maxx:# 记录相似度最大的两个簇
                        maxx = tmp
                        tmpi = i
                        tmpj = j
            if tmpi == -1 or tmpj == -1:
                return maxQ
            if tmpi > tmpj:# 始终保持tmpi < tmpj 便于管理
                tp = tmpi
                tmpi = tmpj
                tmpj = tp
            old = kind[tmpj]
            for i in range(len(kind)):# 将两个簇的标号合并为较小的一个
                if kind[i] == old:
                    kind[i] = kind[tmpi]

            return max(solve(kind,maxQ),maxQ)

        kind = [i for i in range(g.vcount())]
        maxQ = solve(kind,0)
        plt.plot(self.x,self.y)
        plt.show()
        return maxQ
if __name__ == '__main__':

    g = igraph.read(r"C:\Users\86139\Desktop\大三下Python\数据挖掘课堂\DM_3\karate.gml")
    arr = np.array(calCosSimilarity(g))
    cls = myCluster(arr,g)
    a = cls.cluster()
    print(cls.res)
    import networkx as nx
    A = g.get_edgelist()
    G = nx.DiGraph(A)  # In case your graph is directed
    G = nx.Graph(A)  # In case you graph is undirected
    pos = nx.spring_layout(G)
    for i in range(len(G.nodes)):
        G.nodes[i]["id"] = str(i + 1)
    nx.draw(G,pos, cmap=plt.get_cmap('jet'), node_color=cls.res,with_labels=nx.get_node_attributes(G,"id"))
    plt.suptitle("Class "+str(len(set(cls.res))))
    plt.show()
