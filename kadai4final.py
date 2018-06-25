# coding: utf-8

ecSortList = []
# ファイルをオープンする
test_data = open("enzyme.txt", "r")

# 一行ずつ読み込んでソート用ナンバーを作る
for line in test_data:
    tempList = line.split("\t")
    del tempList[1]
    tempList[0] = tempList[0][3:]
    ecNum = tempList[0].split(".")
    ecNum[0] = int(ecNum[0])*10**7
    ecNum[1] = int(ecNum[1])*10**5
    ecNum[2] = int(ecNum[2])*10**3
    ecNum[3] = int(ecNum[3])
    ecSortNum = ecNum[0]+ecNum[1]+ecNum[2]+ecNum[3]
    ecSortList.append(ecSortNum) #ナンバーをソート
ecSortList = sorted(ecSortList)

#ソート用ナンバーをec番号に変換
for num in ecSortList:
    print("ec:",end="")
    ecNum0 = num // 10**7
    ecNum1 = (num // 10**5)%(10**2)
    ecNum2 = (num // 10**3)%(10**2)
    ecNum3 = num % 10**3
    print(str(ecNum0) + "." + str(ecNum1) + "." + str(ecNum2) + "." + str(ecNum3))

test_data.close()
