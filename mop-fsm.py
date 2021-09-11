###############################################################################
# Getter functions
###############################################################################

def filter_comments(filename):
    filtered = ""
    with open(filename) as bf:
        line = bf.readline()
        while line:
            if line[0] == '#':
                line = bf.readline()
                continue
            else:
                filtered += line
            line = bf.readline()
        bf.close()
    return filtered

def get_baseline(basefile):
    bfstr = filter_comments(basefile)
    
    # Process more
    return bfstr

def mop_process_states(mopfile):
    print(mopfile)
    return mopfile.read()

def mop_process_transitions(mopfile):
    print(mopfile)
    return mopfile.read()

def get_mop(mopfile):
    mfstr = ""
    with open(mopfile) as mf:
        line = mf.readline()
        while line:
            if '#' in line:
                pass
            elif 'states:' in line:
                mfstr += mop_process_states(mf)
            elif 'transitions:' in line:
                mfstr += mop_process_transitions(mf)
            line = mf.readline()
        mf.close()

    # Process more
    return mfstr

get_mop("state-machine.mop")
#print(get_baseline("fsm-baseline.bl"))


###############################################################################
# Generators
###############################################################################

