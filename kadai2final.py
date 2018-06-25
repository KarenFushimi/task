# coding: utf-8

codontable = {
        'A': ['GCA', 'GCC', 'GCG', 'GCT'],
        'C': ['TGC', 'TGT'],
        'D': ['GAC', 'GAT'],
        'E': ['GAA', 'GAG'],
        'F': ['TTC', 'TTT'],
        'G': ['GGA', 'GGC', 'GGG', 'GGT'],
        'H': ['CAC', 'CAT'],
        'I': ['ATA', 'ATC', 'ATT'],
        'K': ['AAA', 'AAG'],
        'L': ['CTA', 'CTC', 'CTG', 'CTT', 'TTA', 'TTG'],
        'M': ['ATG'],
        'N': ['AAC', 'AAT'],
        'P': ['CCA', 'CCC', 'CCG', 'CCT'],
        'Q': ['CAA', 'CAG'],
        'R': ['AGA', 'AGG', 'CGA', 'CGC', 'CGG', 'CGT'],
        'S': ['AGC', 'AGT', 'TCA', 'TCC', 'TCG', 'TCT'],
        'T': ['ACA', 'ACC', 'ACG', 'ACT'],
        'V': ['GTA', 'GTC', 'GTG', 'GTT'],
        'W': ['TGG'],
        'Y': ['TAC', 'TAT'],
        }

numCount = 0
numTotal = 1

print("アミノ酸配列を入力してください")
print("A,C,D,E,F,G,H,I,K,L,M,N,P,Q,R,S,T,V,W,Y")
aminoStr = input()

for amino in aminoStr:
    numCodon = len(codontable[amino])
    numTotal *= numCodon

num1 = numTotal
num2 = numTotal
aminoLeng = len(aminoStr)

for numCount in range(numTotal):
    for amino in range(aminoLeng):
        num1 = num2
        num2 = num1 / len(codontable[aminoStr[amino]])
        if (numCount % num1) // num2 == 0:
            print(codontable[aminoStr[amino]][0], end="")
        elif (numCount % num1) // num2 == 1:
            print(codontable[aminoStr[amino]][1], end="")
        elif (numCount % num1) // num2 == 2:
            print(codontable[aminoStr[amino]][2], end="")
        elif (numCount % num1) // num2 == 3:
            print(codontable[aminoStr[amino]][3], end="")
        elif (numCount % num1) // num2 == 4:
            print(codontable[aminoStr[amino]][4], end="")
        elif (numCount % num1) // num2 == 5:
            print(codontable[aminoStr[amino]][5], end="")

    print("")
    num2 = numTotal
