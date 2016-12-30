# -*- encoding:utf-8 -*-

def aliveList(path, nodenum):
    '''  CHECK ALIVE  '''
    ret = list()
    for i in range(nodenum):
        fp = open("%s%din"%(path, i), "r")
        isalive = float(fp.readline().split('#')[1])
        #print(isalive)
        if isalive != float(0.0):
            ret.append(i)

    return ret

def alive(path, node):
    fp = open("%s%din"%(path, node), "r")
    isalive = float(fp.readline().split('#')[1])
    if isalive != float(0.0):
        return str(node)
    else:
        return 'null'

#print(aliveList('room/node', 4))