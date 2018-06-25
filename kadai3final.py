# coding: utf-8

# ファイルをオープンする
test_data = open("NC_001416.fna", "r")

# 行ごとにすべて読み込んでリストデータにする
lines = test_data.readlines()
del lines[0]

for line in lines:
    line = line.rstrip()
    #print(line)

strNuc = ''.join(lines) #塩基配列

cutList = [-3,len(strNuc)-3]
enzymes = {"EcoRI":"GAATTC", "HindIII":"AAGCTT","BamHI":"GGATCC", "NotI":"GCGGCCGC"}

for (enzyme, nuc) in enzymes.items(): #各酵素についてループ

    intNum = 0 #検索開始位置
    locationE1 = -3 #断片の開始位置の初期値。場合分け減らすため-3
    locationE2 = 0 #断片の終端位置の初期値。

    print(enzyme +"切断時の各断片の長さは")

    while(locationE2 != -1): #切断配列がある場合
        locationE2 = strNuc.find(nuc ,intNum) #切断配列の検索
        if(locationE2 == -1): #最後
            length = len(strNuc) - locationE1 - 3
            print(str(length) + "\n")
        else: #それ以外
            length = locationE2 - locationE1
            print(length, end=",")
            cutList.append(locationE2) #全酵素切断時計算用リスト
        intNum = locationE2 + 1
        locationE1 = locationE2

cutList = sorted(cutList)

print("全酵素で切断時の断片の長さは") #全酵素での切断
for num in range(0,len(cutList)-1):
    length = cutList[num+1]-cutList[num]
    if(num == len(cutList)-1):
        print(str(length) + "\n")
    else:
        print(length, end=",")


# ファイルをクローズする
test_data.close()