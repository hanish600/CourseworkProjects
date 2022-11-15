import matplotlib.pyplot as plt
from tabulate import tabulate
import math

def main():
    M = pktMaker()
    table=[]
    title=["Number of packets (M)","Tranmission Time (ns)"] 
    transtimes = transTimes(M)
    table.append(title)
    for i in range(50):
        newlist = [M[i],transtimes[i]]
        table.append(newlist)
    """
    Part A and B
    
    print(tabulate(table))
    minT = transtimes.index(min(transtimes))
    print("Minimum transmission time: ",transtimes[minT],'\n',
          "M Value: ",M[minT],sep="")
    """
    
    """
    Part C
    
    plt.plot(M,transtimes)
    plt.ylabel("Transmission time (ns) ")
    plt.xlabel("Number of Packets (M) ")
    """
    
    """
    Part D

    mOptimal,TTT = mOpt()
    print("Optimal Time: ", mOptimal,
          '\n',"Total tranmission Time: ",TTT,sep="")
    """
    
def pktMaker():
    arr=[]
    for i in range(50):
        arr.append(i+1)
    return arr

def transTimes(M):
    hdr = 5
    hops = 8
    usrData = 100
    tTimes = []
    for i in range(50):
        pktTime = hdr + (usrData/M[i])
        TTT = (M[i] + hops-1) * pktTime
        TTT = round(TTT,2)
        tTimes.append(TTT)
    return tTimes

def mOpt():
    hops = 8
    usrData = 100
    hdr = 5
    inside_m_Opt = (hops - 1 ) * usrData
    inside_m_Opt /= hdr
    Mopt = math.sqrt(inside_m_Opt)
    pktTime = hdr + (usrData/Mopt)
    TTT = (Mopt + hops-1) * pktTime
    TTT = round(TTT,2)
    return Mopt,TTT
    

main()