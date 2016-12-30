# -*- encoding:utf-8 -*-

import os
import CheckAlive

alst = CheckAlive.aliveList('room/node',4)
print(alst)
def node01cmd(node):
    cmd = 'bin/node'+CheckAlive.alive('room/node', node)+\
            ' room/node%din room/node%dout'%(node, node)
    return os.system(cmd)

def node23cmd(node):
    cmd = 'bin/node%dgen'%node+' room/node %d %d'%(node-2,node)
    os.system(cmd)
    cmd = 'bin/node'+CheckAlive.alive('room/node', node)+\
            ' room/node%din room/node%dout'%(node, node)
    return os.system(cmd)

for node in alst:
    if node < 2:
        node01cmd(node)
    elif node>1:
        node23cmd(node)

alst = CheckAlive.aliveList('room/node',4)
print(alst)