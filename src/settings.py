from matplotlib import rc
#rc('font',**{'family':'sans-serif','sans-serif':['Helvetica']})
#rc('text', usetex=True)
colors = {'min CD':'m', 'median CD':'k', 'max CD':'m',
        'min TranSync':'g', 'median TranSync':'b', 'max TranSync':'g', 'CD':'k',
        'TranSync':'b'}
linestyles = {'min CD':'-', 'median CD':'-', 'max CD':'-',
        'min TranSync':'-', 'median TranSync':'-', 'max TranSync':'-','CD':'-',
        'TranSync':'-'}
linewidths = {'min CD':0.01, 'median CD':1, 'max CD':0.01,
        'min TranSync':0.01, 'median TranSync':1, 'max TranSync':0.01,'CD':1,
        'TranSync':1}
markers = {'min CD':'', 'median CD':'', 'max CD':'',
        'min TranSync':'', 'median TranSync':'', 'max TranSync':'','CD':'',
        'TranSync':''}

#graph1 = {'id':1, 'loc_g':(0.45, 0.45), 'loc_t':(0.3, 0.55), 'fs_g':19,
#        'fs_t':36, 'title':'Graph $G_{dr}$', 'max_diff':1, 'max_time':3}
#graph2 = {'id':2, 'loc_g':(0.57, 0.57), 'loc_t':(0.3, 0.55), 'fs_g':15,
#        'fs_t':36, 'title':'Graph $G_{di}$', 'max_diff':1, 'max_time':4}
#graph3 = {'id':3, 'loc_g':(0.03, 0.13), 'loc_t':(0.03, 0.23), 'fs_g':20,
#        'fs_t':25, 'title':'Graph $G_{sr}$', 'max_diff':2.0, 'max_time':18}
#graph4 = {'id':4, 'loc_g':(0.03, 0.13), 'loc_t':(0.03, 0.13), 'fs_g':24,
#        'fs_t':30, 'title':'Graph $G_{si}$', 'max_diff':2.8, 'max_time':15}
graph1 = {'id':1, 'loc_g':(0.45, 0.45), 'loc_t':(0.37, 0.55), 'fs_g':19,
        'fs_t':33, 'title':'Graph $G_{dr}$', 'max_diff':1, 'max_time':3}
graph2 = {'id':2, 'loc_g':(0.57, 0.57), 'loc_t':(0.3, 0.55), 'fs_g':15,
        'fs_t':36, 'title':'Graph $G_{di}$', 'max_diff':1, 'max_time':4}
graph3 = {'id':3, 'loc_g':(0.03, 0.13), 'loc_t':(0.03, 0.23), 'fs_g':20,
        'fs_t':25, 'title':'Graph $G_{sr}$', 'max_diff':2.0, 'max_time':18}
graph4 = {'id':4, 'loc_g':(0.03, 0.03), 'loc_t':(0.03, 0.13), 'fs_g':24,
        'fs_t':36, 'title':'Graph $G_{si}$', 'max_diff':2.8, 'max_time':15}
setting_map = {'graph1':graph1,
        'graph1_final':graph1, 'graph2_final':graph2, 'graph3_final':graph3,
        'graph4_final':graph4}
#dash = {'TRWS':[4, 2, 1, 2], 'AD3':[1, 1, 1, 1], 'PSDD':[4, 2, 4, 2, 1, 2], 'MPLP':[1, 2, 1, 2], 'GDMM':[], 'Soft-BCFW':[4, 2, 4, 2], 'Soft-BCFW-acc':[2, 4, 2, 4], 'LPsparse':[4, 2, 1, 2, 1, 2], 'smoothMSD':[]}

eps=1e-5
title_fontsize=38
