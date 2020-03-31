from Bio import SeqIO
from Bio.SeqUtils.ProtParam import ProteinAnalysis

for record in SeqIO.parse('TTN.fasta', 'fasta'):
    X = ProteinAnalysis(str(record.seq))
    print('\n### Results for record: {} ###'.format(record.id))
    print(X.count_amino_acids()['A']) 
    print(X.count_amino_acids()['E']) 
    print("%0.2f" % X.get_amino_acids_percent()['K']) 
    print("%0.2f" % X.get_amino_acids_percent()['L']) 
    print("%0.2f" % X.molecular_weight()) 
    print("%0.2f" % X.aromaticity()) 
    print("%0.2f" % X.instability_index()) 
    print("%0.2f" % X.isoelectric_point()) 
    sec_struc = X.secondary_structure_fraction() 
    print("%0.2f" % sec_struc[0]) 
    epsilon_prot = X.molar_extinction_coefficient()  
    print(epsilon_prot[0])   
    print(epsilon_prot[1]) 
    print(X.count_amino_acids())