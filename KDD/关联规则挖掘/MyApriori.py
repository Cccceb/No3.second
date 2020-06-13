import pandas as pd
import numpy as np
import sys
sys.stdout = open("./out.txt", "w")
def caluSupp(dataset, Ck, minSupport):
    total = 435
    Ck = list(Ck)
    tmp = {}
    for tid in dataset:
        for can in Ck:
            if can.issubset(tid): # can是一个集合类型
                if can not in tmp.keys():
                    tmp[can] = 1
                else:
                    tmp[can] += 1
    freqSet = []
    supportData = {}
    for key in tmp:
        # 计算支持度
        support = tmp[key] / total
        if support >= minSupport:
            # 将满足阈值的放入频繁项集中
            freqSet.append(key)
        # 记录所有的支持度
        supportData[key] = support
    return freqSet, supportData
def aprioriGen(Lk, k):
    retList = []
    lenLk = len(Lk)

    for i in range(lenLk):
        for j in range(i + 1, lenLk):
            L1 = list(Lk[i])[: k - 2]
            L2 = list(Lk[j])[: k - 2]
            L1.sort()
            L2.sort()
            # 对于前k-2项相同的两个集合进行合并，计入到k项集中
            if L1 == L2:
                # print(Lk[i] | Lk[j], Lk[i], Lk[j])
                retList.append(Lk[i] | Lk[j])
    return retList


# 找出数据集 dataSet 中支持度 >= 最小支持度的候选项集以及它们的支持度。即我们的频繁项集。
def apriori(dataSet, minSupport):
    a = [[i] for i in range(1,18)]
    b = [[i] for i in range(0,-18,-1)]
    a.extend(b)
    C1 = map(frozenset,a)
    # 对每一行进行 set 转换，然后存放到集合中
    dataSet = list(map(set, dataSet))
    # print 'dataSet=', dataSet
    # 计算候选数据集 C1 在数据集 dataSet 中的支持度，并返回支持度大于 minSupport 的数据
    L1, supportData = caluSupp(dataSet, C1, minSupport)

    freqSet = [L1] # frequency为所有频繁项集
    k = 2
    while (len(freqSet[k - 2]) > 0):
        # 从候选2-项集开始计算，直到
        Ck = aprioriGen(freqSet[k - 2],k) # 合并得到候选k项集

        Lk, supK = caluSupp(dataSet, Ck, minSupport)  # 计算频繁k-项集
        # 将新产生的项集的支持度计数加入到集合中
        supportData.update(supK)
        if len(Lk) == 0:
            break
        freqSet.append(Lk)
        k += 1
    return freqSet, supportData
def calcConf(freqSet, subSet, supportData, brl, minConf):
    # subSet 是集合的列表，包含本次要判断的规则的右部集合
    # brl包括中所有的规则的元组的列表
    retList = []
    for conseq in subSet:
        # print(freqSet," ",freqSet - conseq)
        # print(supportData[freqSet]," ",supportData[freqSet - conseq])
        conf = supportData[freqSet] / supportData[freqSet - conseq]
        # 支持度定义: a -> b = support(a | b) / support(a).
        if conf >= minConf:
            print(freqSet - conseq, '->', conseq, 'confidence:', conf)
            brl.append((freqSet - conseq, conseq, conf))
            retList.append(conseq)
    return retList
def generateRules(L, supportData, minConf):
    ruleList = []
    for i in range(1, len(L)):# L[i]为所有i+1项集构成的列表
        for freqSet in L[i]:
            H1 = [frozenset([item]) for item in freqSet] # 频繁项集中所有元素形成的列表
            if i > 1:# 2以上的项集，还需要递归的扩大关联规则的右部
                rulesFromConseq(freqSet, H1, supportData, ruleList, minConf)
            else:# 频繁2-项集，只需要计算两个置信度，所以单拿出来
                calcConf(freqSet, H1, supportData, ruleList, minConf)
    return ruleList

def rulesFromConseq(freqSet, H, supportData, brl, minConf):
    Hmp1 = calcConf(freqSet, H, supportData, brl, minConf)  # 利用阈值进行过滤，返回可信度大于阈值的集合

    if (len(Hmp1) >= 1):
        m = len(H[0])
        if m < len(freqSet)-1: # 当关联规则的右部小于频繁项集的长度时
            Hmp1 = aprioriGen(H, m+1) # 利用合并函数将规则右部扩展一位
            # 如果仍有满足阈值的规则，那么递归的合并规则，并进行过滤，直到没有满足阈值要求的规则
            rulesFromConseq(freqSet, Hmp1, supportData, brl, minConf)



if __name__ == '__main__':
    import joblib
    dataset = joblib.load("./MyDataset")
    L, supportData = apriori(dataset, minSupport=0.3)
    print("frequency",L)
    print("supportData",supportData)
    rules = generateRules(L, supportData, minConf=0.9)
    names = []
    print(rules)
    print(len(rules))

