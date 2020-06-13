import math
import numpy as np
from sklearn.metrics import roc_curve, auc ###计算roc和auc
import matplotlib.pyplot as plt
def calc_shannon_ent(dataSet): # 计算信息熵
    num_entries = len(dataSet)  # 返回数据集的行数
    label_counts = {} # 保存每个标签出现的次数
    # 为所有可能分类创建字典
    for featVec in dataSet:# 对每组特征向量进行统计
        current_label = featVec[-1] # 提取标签信息
        if current_label not in label_counts.keys():# 如果标签没有放入统计次数的字典，则加入
            label_counts[current_label] = 0
        label_counts[current_label] += 1# 标签计数
    shannoent = 0.0
    # 以二为底求对数
    for key in label_counts:
        prob = float(label_counts[key])/num_entries
        shannoent -= prob * math.log(prob, 2)
    return shannoent

def has_key(dict,value):
    if value in dict.keys():
        return dict[value]
    else:
        return 0.0
def split_dataset(dataSet, axis, value):# 取出第axis列等于value的特征
    tmp = dataSet[dataSet[:,axis]==value]
    return np.delete(tmp,axis,axis=1)


def choose_best(dataSet): # 按照信息增益，计算最好的分类标准
    numFeatures = len(dataSet[0]) - 1 # 减去标签
    baseEntropy = calc_shannon_ent(dataSet) # 整体的熵
    bestInfoGain = 0.0
    bestFeature = -1

    # 创建唯一分类标签
    for i in range(numFeatures):
        featList = list(dataSet[:,i])
        uniqueValis = set(featList)
        newEntropy = 0.0

        # 计划每种划分的信息墒
        for value in uniqueValis: # 循环每种取值
            subDataSet = split_dataset(dataSet, i ,value) # 对于第i类取值为
            prob = len(subDataSet)/float(len(dataSet))
            newEntropy += prob * calc_shannon_ent(subDataSet)
            infoGain = baseEntropy - newEntropy

            # 计算最好的增益墒
            if infoGain > bestInfoGain:
                bestInfoGain = infoGain
                bestFeature = i

    return bestFeature
def majoritycnt(classList): # 实现多数票决函数
    classCount = {}
    for vote in classList:
        if vote not in classCount.keys():
            classCount[vote] = 0
        classCount[vote] += 1
    # return max(classCount,key=classCount.get)# 返回最大的值对应的键
    return has_key(classCount,1)/len(classList)

def create_tree(dataSet, labels,min_samples_split=1): # 创建决策树
    classList = list(dataSet[:,-1]) # 得到所有的标签
    if len(dataSet)<=min_samples_split:
        return majoritycnt(classList)
    if len(dataSet[0]) == 1:
        # 停止分割直至没有更多特征，则多数票决
        return majoritycnt(classList)
    if classList.count(classList[0]) == len(classList):
        # 停止分类直至所有类别相等,都是classList[0]
        return 1.0 if classList[0] == 1 else 0.0

    bestfaet = choose_best(dataSet)# 根据信息熵计算最优标签
    # print(labels,bestfaet)
    bestfaetlabel = labels[bestfaet]
    mytree = {bestfaetlabel:{}} # 根据最有特征的标签生成树
    del(labels[bestfaet])# 删除已经使用的标签
    # 得到包含所有属性的列表
    featvalues = list(dataSet[:,bestfaet])
    uniquevalues = set(featvalues) # 去掉重复的属性
    for value in uniquevalues: # 遍历特征创建决策树
        sublables = labels[:]
        mytree[bestfaetlabel][value] = create_tree(split_dataset(dataSet, bestfaet, value), sublables,min_samples_split)

    return mytree

def test_tree(inputtree, featlabels, testdata,Y_test):
    prob = np.array([classify(inputtree, featlabels,testdata[i]) for i in range(len(testdata))]).reshape(-1,1)
    pred =np.array([1 if i>0.5 else 0 for i in prob]).reshape(-1,1)
    acc = (pred==Y_test).sum()/len(Y_test)
    print("-ACC",acc)
    print(prob)
    fpr, tpr, threshold = roc_curve(Y_test, prob)  # 计算真正率和假正率
    roc_auc = auc(fpr, tpr)  # 计算auc的值
    plt.figure()
    lw = 2
    plt.figure(figsize=(10, 10))
    plt.plot(fpr, tpr, color='darkorange',
             lw=2*lw, label='ROC curve (area = %0.3f)' % roc_auc)  ###假正率为横坐标，真正率为纵坐标做曲线
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.0])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver operating characteristic example')
    plt.legend(loc="lower right")
    plt.show()
    return acc
def classify(inputtree, featlabels, testvec):
    firststr = list(inputtree.keys())[0]
    seconddict = inputtree[firststr]
    featindex = featlabels.index(firststr)
    key = testvec[featindex]
    if key not in seconddict.keys(): # 如果这个没有见过。那么随机一个打分
        valueoffeat = np.random.rand()
    else:
        valueoffeat = seconddict[key]
    if isinstance(valueoffeat, dict):
        classlabel = classify(valueoffeat, featlabels, testvec)
    else:
        classlabel = valueoffeat
    return classlabel

if __name__ == '__main__':
    import pandas as pd
    k = 10000
    X_test = pd.read_csv("./X_test.csv").astype(int)[:k]
    XX = X_test.copy().values
    Y_test = pd.read_csv("./Y_test.csv", header=None)[:k]
    dataset = np.hstack((X_test.values,Y_test.values))
    labels = list(X_test.columns.values)
    feature = labels.copy()
    DecTree = create_tree(dataset,labels,1)
    print(DecTree)
    result = test_tree(DecTree,feature,XX, Y_test.values.reshape(-1,1))
