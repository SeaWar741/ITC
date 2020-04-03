from Bio import SeqIO
from Bio.SeqUtils.ProtParam import ProteinAnalysis

print("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\nTTN")
for record in SeqIO.parse('TTN.fasta', 'fasta'):
    X = ProteinAnalysis(str(record.seq))
    print('\nResults for record: {} ###'.format(record.id))
    print(X.count_amino_acids()['A']) 
    print(X.count_amino_acids()['E']) 
    print("A percentage :%0.2f" % X.get_amino_acids_percent()['A']) 
    print("T percentage :%0.2f" % X.get_amino_acids_percent()['T']) 

    print("C percentage :%0.2f" % X.get_amino_acids_percent()['C']) 
    print("G percentage :%0.2f" % X.get_amino_acids_percent()['G']) 

    print("%0.2f" % X.molecular_weight()) 
    print("%0.2f" % X.aromaticity()) 
    print("%0.2f" % X.instability_index()) 
    print("%0.2f" % X.isoelectric_point()) 
    sec_struc = X.secondary_structure_fraction() 
    print("%0.2f" % sec_struc[0]) 
    epsilon_prot = X.molar_extinction_coefficient()  
    print(epsilon_prot[0])   
    print(epsilon_prot[1]) 
    composition1 = X.count_amino_acids()

print("*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\nTCF7L2:")
for record in SeqIO.parse('TCF7L2.fasta', 'fasta'):
    X = ProteinAnalysis(str(record.seq))
    
    print('\nResults for record: {} ###'.format(record.id))
    print(X.count_amino_acids()['A']) 
    print(X.count_amino_acids()['E']) 
    print("A percentage :%0.2f" % X.get_amino_acids_percent()['A']) 
    print("T percentage :%0.2f" % X.get_amino_acids_percent()['T']) 

    print("C percentage :%0.2f" % X.get_amino_acids_percent()['C']) 
    print("G percentage :%0.2f" % X.get_amino_acids_percent()['G']) 

    print("%0.2f" % X.molecular_weight()) 
    print("%0.2f" % X.aromaticity()) 
    print("%0.2f" % X.instability_index()) 
    print("%0.2f" % X.isoelectric_point()) 
    sec_struc = X.secondary_structure_fraction() 
    print("%0.2f" % sec_struc[0]) 
    epsilon_prot = X.molar_extinction_coefficient()  
    print(epsilon_prot[0])   
    print(epsilon_prot[1]) 
    composition1 = X.count_amino_acids()

def maxRepeating(str): 
    l = len(str) 
    count = 0
    # Find the maximum repeating  
    # character starting from str[i] 
    res = str[0] 
    for i in range(l):    
        cur_count = 1
        for j in range(i + 1, l): 
      
            if (str[i] != str[j]): 
                break
            cur_count += 1
        # Update result if required 
        if cur_count > count : 
            count = cur_count 
            res = str[i] 
    return res 


print("\nRepetitions TTN")
with open('TTN.fasta','r') as file:
    data = file.read()
    for x in sorted(set(data)):
        i = 1;
        while x*i in data:
            i+=1
        print(x,"-",i)

print("\nRepetitions TCF7L2")
with open('TCF7L2.fasta','r') as file:
    data = file.read()
    for x in sorted(set(data)):
        i = 1;
        while x*i in data:
            i+=1
        print(x,"-",i)