import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.metrics import accuracy_score, recall_score, f1_score
from sklearn.metrics import roc_curve, auc ###计算roc和auc
import joblib

from 数据挖掘课堂.DM_1.DecTree import create_tree, test_tree


def get_genre_names(movies):
    # 得到电影类型的稀疏矩阵
    genres = movies["Genres"]
    genres_lst = []
    for i in range(len(genres)):
        genres_lst += genres[i].split("|")
    genres_lst =["MovieID"] + list(set(genres_lst))
    df = pd.DataFrame(columns= genres_lst)
    df["MovieID"] = movies["MovieID"].values
    s = pd.Series()
    for i in range(len(genres)):
        lst = genres[i].split("|")
        for j in range(len(lst)):
            df.loc[i,lst[j]]= 1
    return df.fillna(0)
def fill_users_gerners(users,X_train,path,movies = pd.read_csv("movies_genres.csv")):
    movie_name = ['Mystery', 'Film-Noir', 'Fantasy', 'Comedy', "Children's", 'Drama',
                  'Romance', 'Horror', 'Thriller', 'Sci-Fi', 'Documentary', 'Action',
                  'Animation', 'War', 'Crime', 'Musical', 'Adventure', 'Western']
    feature = pd.DataFrame(np.zeros((len(X_train), 22)), columns=list(users.columns.values)+movie_name)
    for i in range(len(X_train)):
        u_id = X_train.loc[i,"UserID"]
        m_id = X_train.loc[i,"MovieID"]
        feature.loc[i,"UserID":"Occupation"] = users.loc[u_id-1,"UserID":"Occupation"]
        feature.loc[i, "Mystery":"Western"] = movies.loc[movies["MovieID"]==m_id,"Mystery":"Western"].values
    feature.to_csv(path,encoding="gbk",index=False)
    # 构建新的df，包括UserID,MovieID 和所有电影类型的稀疏矩阵
    # users = pd.DataFrame(np.zeros((6041, len((movie_name)))), columns=movie_name)
    # user_num = users.copy()
    # for i in range(len(X_train)):
    #     xt = X_train.loc[i]
    #     rat = Y_train.loc[i].values[0]
    #     movie = movies[movies["MovieID"]==xt["MovieID"]]
    #     u_id = xt["UserID"]-1
    #     genres = movie["Genres"].values[0].split("|")
    #     for g in genres:
    #         users.loc[u_id,g] += rat
    #         user_num.loc[u_id,g] += 1
    #
    # user_num[user_num==0] = 1
    # users /= user_num
    # users.to_csv("users_ratings.csv",encoding="gbk",index=False)
    # return users

def classifier(users):
    ratings = pd.read_csv("./users_ratings.csv")
    # users 为用户信息表,ratings 为 用户对所有类的打分情况
    gerner_name = ratings.columns.values
    users = users.drop("UserID",axis = 1)
    model  = dict()
    w = dict()
    for gn in gerner_name:
        from sklearn.tree import DecisionTreeClassifier
        clf = DecisionTreeClassifier(criterion="entropy")
        # from sklearn.naive_bayes import GaussianNB, BernoulliNB  # 二值的选伯努利贝叶斯，符合高斯分布的选高斯贝叶斯
        # clf = BernoulliNB()
        # from sklearn.ensemble import RandomForestClassifier
        # clf = RandomForestClassifier(n_estimators= 81)
        inx = ratings[ratings[gn]!=0].index # 选择出给该类型投过票的用户索引
        Y_part  = ratings.loc[inx,gn].values
        Y_part[Y_part <= 3] = 0
        Y_part[Y_part >  3] = 1
        X_part = users.loc[inx].values
        # print(Y_part)
        # print(X_part)
        clf.fit(X_part, Y_part)
        Y_pred = clf.predict(X_part)
        print("-ACC",accuracy_score(Y_part,Y_pred))
        model[gn] = clf
        w[gn] = float(len(inx)/len(ratings))
    joblib.dump(model,"models") # 保存模型
    joblib.dump(w,"w")
    theta = dict()
    return model
def predict(user,movie,model,thd):
    score = 0.0
    flag = 0
    genres = movie["Genres"].values[0].split("|")
    for g in genres:
        clf = model[g]
        p = clf.predict_proba(user)[0,1]
        score += p
        flag += clf.predict(user)
    if score > thd:
        return 1,score
    else :
        return 0,score

def test_model(users,movies,model = joblib.load("models")):
    k = 1000
    X_test = pd.read_csv("./X_test_1.csv").loc[:k]
    Y_test = pd.read_csv("./Y_test_1.csv",header = None).loc[:k]
    Y_test[Y_test <= 3] = 0
    Y_test[Y_test >  3] = 1
    threshold = 0.0
    accuracy = 0
    for thd  in np.arange(0.0,2,0.01):
        thd = 1.0
        pred = []
        scores = []
        for i in range(len(X_test)):
            user_id = X_test.loc[i,"UserID"]
            user = users[users["UserID"] == user_id].drop("UserID",axis=1)
            movie_id = X_test.loc[i,"MovieID"]
            movie = movies[movies["MovieID"] == movie_id]
            prt,sco = predict(user, movie, model,thd)
            pred.append(prt)
            scores.append(sco)
        acc = accuracy_score(Y_test.values,pred)
        if acc > accuracy:
            accuracy = acc
            threshold = thd
    print("-threshold",threshold)
    print("-ACC",accuracy)
    print("-ACC",acc)
    fpr, tpr, threshold = roc_curve(Y_test.values, scores)  # 计算真正率和假正率

    roc_auc = auc(fpr, tpr)  # 计算auc的值
    plt.figure()
    lw = 2
    plt.figure(figsize=(10, 10))
    plt.plot(fpr, tpr, color='darkorange',
             lw=lw, label='ROC curve (area = %0.3f)' % roc_auc)  ###假正率为横坐标，真正率为纵坐标做曲线
    plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.0])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title('Receiver operating characteristic example')
    plt.legend(loc="lower right")

    plt.show()

def read_data():
    users_cols = ["UserID", "Gender", "Age", "Occupation", "Zip-code"]
    users =pd.read_table('./ml-1m/users.dat',sep="::",names = users_cols, engine='python')
    users.loc[users["Gender"]=="F","Gender"] = 0
    users.loc[users["Gender"]=="M","Gender"] = 1
    users = users.drop("Zip-code", axis=1)
    movies_cols = ["MovieID", "Title", "Genres"]
    movies =pd.read_table('./ml-1m/movies.dat',sep="::",names = movies_cols,engine='python')
    rating_cols = ["UserID", "MovieID", "Rating", "Timestamp"]
    ratings = pd.read_table('./ml-1m/ratings.dat',sep="::",names = rating_cols,engine='python')
    return users.astype(int),movies,ratings
def classifier2(X_train,Y_train,X_validation,Y_validation):
    X_train = X_train.drop("UserID",axis = 1)

    # print("train\n",Y_train.value_counts())
    from sklearn.tree import DecisionTreeClassifier
    Accuracy = 0
    min_samples_split = min_samples_leaf = 0
    msp = 5
    msl = 102
    clf = DecisionTreeClassifier(criterion="entropy", min_samples_split=msp, min_samples_leaf=msl)
    clf.fit(X_train, Y_train)
    pred = clf.predict(X_train)
    acc = accuracy_score(Y_train, pred)
    print("-ACC_On_Train", acc)
    if X_validation is not None:
        X_validation = X_validation.drop("UserID",axis = 1)
        pred = clf.predict(X_validation)
        acc = accuracy_score(Y_validation, pred)
        print("-ACC_On_validation", acc)
    # for msp in range(5,120,5):
    #     for msl in range(2,120,2):
    #         clf = DecisionTreeClassifier(criterion="entropy",min_samples_split=msp,min_samples_leaf = msl)
    #         clf.fit(X_train,Y_train)
    #         pred = clf.predict(X_validation)
    #         acc = accuracy_score(Y_validation,pred)
    #         print("-ACC",acc)
    #         if acc > Accuracy:
    #             Accuracy = acc
    #             min_samples_split = msp
    #             min_samples_leaf = msl
    #             print("-MSP",min_samples_split)
    #             print("-MSL",min_samples_leaf)
    # print("min_samples_split",min_samples_split)
    # print("min_samples_leaf",min_samples_leaf)
    return clf
def test_model2(clf,X_test,Y_test):
    X_test = X_test.drop("UserID",axis = 1)
    # print("test\n",Y_test.value_counts())
    pred = clf.predict(X_test)
    acc = accuracy_score(Y_test,pred)
    print("-ACC_On_Test",acc)
    # scores = clf.predict_proba(X_test)[:,1]
    # fpr, tpr, threshold = roc_curve(Y_test.values, scores)  # 计算真正率和假正率
    # roc_auc = auc(fpr, tpr)  # 计算auc的值
    # plt.figure()
    # lw = 2
    # plt.figure(figsize=(10, 10))
    # plt.plot(fpr, tpr, color='darkorange',
    #          lw=2*lw, label='ROC curve (area = %0.3f)' % roc_auc)  ###假正率为横坐标，真正率为纵坐标做曲线
    # plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
    # plt.xlim([0.0, 1.0])
    # plt.ylim([0.0, 1.0])
    # plt.xlabel('False Positive Rate')
    # plt.ylabel('True Positive Rate')
    # plt.title('Receiver operating characteristic example')
    # plt.legend(loc="lower right")
    # plt.show()
if __name__ == '__main__':
    # users,movies,ratings= read_data()
    ################################################# 将源打分文件转换成由用户属性和电影分类为列标的稀疏矩阵 #################################################
    # fill_users_gerners(users,ratings,"feature.csv")
    ################################################# 分割数据集，训练集和验证集 #################################################
    # label = ratings["Rating"]
    # label[label <= 3] = 0  # 为了让分割结果尽可能均匀，先进行标签化
    # label[label > 3] = 1
    # feature = pd.read_csv("./feature2.csv").drop("UserID",axis=1).astype(int)
    # X_tt, X_validation, Y_tt, Y_validation = train_test_split(feature, label, test_size=0.2)  # 返回测试集，验证集，测试集标签，验证集标签
    # X_train, X_test, Y_train, Y_test = train_test_split(X_tt, Y_tt, test_size=0.25)
    # X_train.to_csv("X_train.csv",encoding="gbk",index=False)
    # Y_train.to_csv("Y_train.csv",encoding="gbk",index=False)
    # X_test.to_csv("X_test.csv",encoding="gbk",index=False)
    # Y_test.to_csv("Y_test.csv",encoding="gbk",index=False)
    # X_validation.to_csv("X_validation.csv", encoding="gbk", index=False)
    # Y_validation.to_csv("Y_validation.csv", encoding="gbk", index=False)
    ################################################## 训练分类器 #################################################
    # X_train = pd.read_csv("./X_train.csv").astype(int)
    # Y_train = pd.read_csv("./Y_train.csv",header = None).astype(int)
    # X_validation = pd.read_csv("./X_validation.csv").astype(int)
    # Y_validation = pd.read_csv("./Y_validation.csv", header=None).astype(int)
    # labels = list(X_train.columns.values)
    # trainSet = np.hstack((X_train.values,Y_train.values))
    # DecTree = create_tree(trainSet, labels, 5)
    # joblib.dump(DecTree,"DecTree")
    # print(DecTree)
    ################################################ 测试分类器，并画出ROC曲线 ######################################
    X_test = pd.read_csv("./X_test.csv").astype(int)
    Y_test = pd.read_csv("./Y_test.csv", header=None).astype(int)
    # test_model2(clf,X_test,Y_test)
    DecTree = joblib.load("DecTree")
    print(DecTree)
    labels = list(X_test.columns.values)
    test_tree(DecTree,labels,X_test.values,Y_test.values)
    ################################################ 十折交叉验证 ###################################################
    # X = [i for i in range(10)]
    # Y = [i for i in range(10)]
    #
    # X_tt, X[9], Y_tt, Y[9] = train_test_split(feature, label, test_size=1 / 10)
    # X_tt, X[8], Y_tt, Y[8] = train_test_split(X_tt, Y_tt, test_size=1 / 9)
    # X_tt, X[7], Y_tt, Y[7] = train_test_split(X_tt, Y_tt, test_size=1 / 8)
    # X_tt, X[6], Y_tt, Y[6] = train_test_split(X_tt, Y_tt, test_size=1 / 7)
    # X_tt, X[5], Y_tt, Y[5] = train_test_split(X_tt, Y_tt, test_size=1 / 6)
    # X_tt, X[4], Y_tt, Y[4] = train_test_split(X_tt, Y_tt, test_size=1 / 5)
    # X_tt, X[3], Y_tt, Y[3] = train_test_split(X_tt, Y_tt, test_size=1 / 4)
    # X_tt, X[2], Y_tt, Y[2] = train_test_split(X_tt, Y_tt, test_size=1 / 3)
    # X[0], X[1], Y[0], Y[1] = train_test_split(X_tt, Y_tt, test_size=1 / 2)
    # feature = ['Gender', 'Age', 'Occupation', 'Mystery', 'Film-Noir',
    #    'Fantasy', 'Comedy', "Children's", 'Drama', 'Romance', 'Horror',
    #    'Thriller', 'Sci-Fi', 'Documentary', 'Action', 'Animation', 'War',
    #    'Crime', 'Musical', 'Adventure', 'Western']
    # ACC = []
    # for i in range(10):
    #     columns = feature.copy()
    #     print("Round",i)
    #     X_train = X_test = pd.DataFrame(columns=columns)
    #     Y_train = Y_test =  pd.Series()
    #     for j in range(10):
    #         if i!=j:
    #             X_train = X_train.append(X[j])
    #             Y_train = Y_train.append(Y[j])
    #         else:
    #             X_test = X[j]
    #             Y_test = Y[j]
    #     # print(X_train.shape,Y_train.shape)
    #     # print(X_test.shape,Y_test.shape)
    #     # clf = classifier2(X_train,Y_train)
    #     # test_model2(clf, X_test, Y_test)
    #     trainSet = np.hstack((X_train.values,Y_train.values.reshape(-1,1)))
    #     DecTree = create_tree(trainSet, columns, 5)
    #     print(DecTree)
    #     ACC.append(test_tree(DecTree, feature, X_test.values, Y_test.values.reshape(-1,1)))
    # print("Avg_Acc = ",np.mean(ACC))