print("        ______   ____  _____       _      ") 
print("       |_   _ `.|_   \|_   _|     / \     ") 
print("         | | `. \ |   \ | |      / _ \    ") 
print("         | |  | | | |\ \| |     / ___ \   ") 
print("        _| |_.' /_| |_\   |_  _/ /   \ \_ ") 
print("       |______.'|_____|\____||____| |____|") 
                                    
print("\n")
print("                      To")
print(" _______                  _           _           ") 
print("|_   __ \                / |_        (_)          ") 
print("  | |__) |_ .--.   .--. `| |-'.---.  __   _ .--.  ") 
print("  |  ___/[ `/'`\]/ .'`\ \| | / /__\ [  | [ `.-. | ") 
print(" _| |_    | |    | \__. || |,| \__., | |  | | | | ") 
print("|_____|  [___]    '.__.' \__/ '.__.'[___][___||__]") 
print("                                                  \n\n") 

seq = input("Enter the sequence => ").upper()

codontable = { 
        'ATA':'I', 'ATC':'I', 'ATT':'I', 'ATG':'M', 
        'ACA':'T', 'ACC':'T', 'ACG':'T', 'ACT':'T', 
        'AAC':'N', 'AAT':'N', 'AAA':'K', 'AAG':'K', 
        'AGC':'S', 'AGT':'S', 'AGA':'R', 'AGG':'R',                  
        'CTA':'L', 'CTC':'L', 'CTG':'L', 'CTT':'L', 
        'CCA':'P', 'CCC':'P', 'CCG':'P', 'CCT':'P', 
        'CAC':'H', 'CAT':'H', 'CAA':'Q', 'CAG':'Q', 
        'CGA':'R', 'CGC':'R', 'CGG':'R', 'CGT':'R', 
        'GTA':'V', 'GTC':'V', 'GTG':'V', 'GTT':'V', 
        'GCA':'A', 'GCC':'A', 'GCG':'A', 'GCT':'A', 
        'GAC':'D', 'GAT':'D', 'GAA':'E', 'GAG':'E', 
        'GGA':'G', 'GGC':'G', 'GGG':'G', 'GGT':'G', 
        'TCA':'S', 'TCC':'S', 'TCG':'S', 'TCT':'S', 
        'TTC':'F', 'TTT':'F', 'TTA':'L', 'TTG':'L', 
        'TAC':'Y', 'TAT':'Y', 'TAA':'_', 'TAG':'_', 
        'TGC':'C', 'TGT':'C', 'TGA':'_', 'TGG':'W', 
    } 

print("    -----------------------------------------------")
print("   | Please select one of the following:           |")
print("   |                                               |")
print("   | 1. ORF start codon can be anything (preferred)|")
print("   | 2. ORF start codon to use ATG only.           |")
print("   |                                               |")
print("    -----------------------------------------------\n")

choice = int(input("Enter your choice (1/2) : "))
print()

#Check if user has incorrectly entered the sequence
check = True;
for x in seq:
    if(x!='A' and x!='T' and x!='G' and x!='C'):
        check=False

#Converts whole sequence to protein sequence
def dna_to_protein(seq):
    protein = ""
    for i in range(0, len(seq), 3):
        if(i+3>len(seq)):
            break
        codon = seq[i:i + 3]
        protein += codontable[codon]
    return protein


if(check):
    #Finding Complementary Sequence
    comp_seq = ''
    for x in seq:
        if(x=='A'):
            comp_seq += 'T'
        elif(x=='T'):
            comp_seq += 'A'
        elif(x=='G'):
            comp_seq += 'C'
        elif(x=='C'):
            comp_seq += 'G'
    comp_seq = comp_seq[::-1]

    orfs = []
    orfs.append(dna_to_protein(seq))
    orfs.append(dna_to_protein(seq[1::]))
    orfs.append(dna_to_protein(seq[2::]))
    orfs.append(dna_to_protein(comp_seq))
    orfs.append(dna_to_protein(comp_seq[1::]))
    orfs.append(dna_to_protein(comp_seq[2::]))
    if(choice==2):
        prseq1 = []
        for s in orfs:
            pr = ""
            check = False
            for x in s:
                if(x=='M'):
                    check=True;
                if(x=='_'):
                    if(pr!=""):
                        prseq1.append(pr)
                    pr = ""
                    check=False;
                if(check):
                    pr += x
            if(pr!=""):
                prseq1.append(pr)
        if(len(prseq1)==0):
            print("Did not find any Sequence !!!")
        else:
            print("Best in the reading frames is => " + max(prseq1))
    elif(choice==1):
        preseq2 = []
        for s in orfs:
            pr = ""
            for x in s:
                if(x=="_"):
                    break
                else:
                    pr += x
            if(pr!=""):
                preseq2.append(pr)
        i=1
        for s in preseq2:
            print(f"ORF {i}: {s}")
            i+=1
        if(len(preseq2)==0):
            print("Did not find any Sequence !!!")
        else:
            maxLength = max(len(x) for x in preseq2 ) 
            for x in preseq2:
                if(len(x)==maxLength):
                    print("Best in the reading frames is => " + x)
                    break
else:
    print("\n\nEntered Wrong Sequence :(")




print("\n")
print("    ------------------------------    ")
print("    | Program By:                |    ")
print("    |      ☻      Hrishabh Joshi |    ")
print("    |     /▌\                    |    ")
print("    |     / \                    |    ")
print("    |             IIIT Kottayam  |    ")
print("    ------------------------------    ")
print()