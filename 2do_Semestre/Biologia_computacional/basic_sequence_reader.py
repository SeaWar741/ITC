from Bio import SeqIO
from Bio.SeqUtils.ProtParam import ProteinAnalysis

composition1 = {}

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