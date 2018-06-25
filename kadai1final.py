# coding: utf-8
numGene = 0
length = 0
lengthTotal = 0

test_data = open("NC_010473.gff","r")
for line in test_data:
    if(line[0] != "#"):
        list = line.split('\t')
        if(list[2] == "gene" and list[0] != "###"):
            numGene += 1
            length = int(list[4])-int(list[3])+1
            lengthTotal += length
            
print("遺伝子数は"+ str(numGene) +"、遺伝子領域長は"+str(lengthTotal))
test_data.close()

