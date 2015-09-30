import numpy as np
from pylab import *

## CONVERGENCIA

def notredame_convergencia():
    c095 = [0.509119, 0.302075, 0.198991, 0.127336, 0.0839806, 0.0606219, 0.0480089, 0.0378658, 0.031487, 0.0265126, 0.0228915, 0.0200119, 0.017832, 0.0158883, 0.0143364, 0.0129636, 0.0117835, 0.0107435, 0.00985934, 0.00905446, 0.00834414, 0.00768855, 0.00709855, 0.00655922, 0.00607121, 0.00561827, 0.00520868, 0.00482965, 0.00448232, 0.00416337, 0.00387039, 0.00359784, 0.00334757, 0.00311561, 0.00290169, 0.00270469, 0.00252202, 0.0023519, 0.00219413, 0.00204755, 0.00191072, 0.00178394, 0.00166548, 0.00155537, 0.00145273, 0.00135734, 0.00126797, 0.00118527, 0.00110769, 0.00103561, 0.000968206, 0.000905496, 0.000846647, 0.000792107, 0.000740819, 0.000693202, 0.000648547, 0.000607005, 0.000567999, 0.000531821, 0.000497748, 0.000466116, 0.000436388, 0.000408719, 0.000382702, 0.000358579, 0.000335818, 0.000314701, 0.000294803, 0.000276305, 0.000258863, 0.000242689, 0.000227402, 0.000213219, 0.000199833, 0.000187395, 0.000175647, 0.000164752, 0.000154443, 0.000144884, 0.000135849, 0.000127466, 0.000119536, 0.000112184, 0.000105223, 9.87668e-05, 9.2656e-05, 8.69915e-05, 8.1627e-05, 7.66538e-05, 7.19399e-05, 6.75697e-05, 6.34274e-05, 5.95864e-05, 5.5946e-05, 5.25672e-05, 4.93619e-05, 4.63876e-05, 4.35651e-05, 4.09452e-05, 3.8459e-05, 3.61503e-05, 3.39592e-05, 3.19261e-05, 2.99974e-05, 2.82064e-05, 2.65064e-05, 2.49268e-05, 2.34275e-05, 2.20343e-05, 2.07117e-05, 1.94821e-05, 1.83147e-05, 1.72292e-05, 1.61987e-05, 1.52404e-05, 1.43305e-05, 1.3484e-05, 1.26804e-05, 1.19329e-05, 1.12231e-05, 1.0563e-05, 9.93633e-06]

    c085 = [0.455528, 0.241828, 0.142534, 0.0816079, 0.0481566, 0.0311029, 0.0220388, 0.0155528, 0.0115715, 0.00871778, 0.00673477, 0.00526785, 0.00419991, 0.0033482, 0.00270314, 0.00218701, 0.00177867, 0.00145098, 0.0011914, 0.000978969, 0.000807204, 0.00066549, 0.000549746, 0.000454506, 0.000376408, 0.00031166, 0.000258524, 0.000214479, 0.000178101, 0.000148015, 0.000123115, 0.000102398, 8.52463e-05, 7.09879e-05, 5.91544e-05, 4.93343e-05, 4.116e-05, 3.43432e-05, 2.86669e-05, 2.39358e-05, 1.9985e-05, 1.66949e-05, 1.39456e-05, 1.16528e-05, 9.73812e-06]

    c075 = [0.401936, 0.188274, 0.0979143, 0.0494654, 0.0257553, 0.0146776, 0.00917667, 0.0057141, 0.0037512, 0.00249361, 0.00169976, 0.00117312, 0.000825259, 0.000580502, 0.000413527, 0.000295208, 0.000211844, 0.000152483, 0.000110475, 8.00969e-05, 5.82737e-05, 4.2391e-05, 3.08984e-05, 2.25401e-05, 1.64709e-05, 1.20332e-05, 8.80733e-06]

    c065 = [0.348345, 0.141415, 0.0637386, 0.0279068, 0.012593, 0.00621968, 0.00337016, 0.00181871, 0.00103476, 0.000596143, 0.000352177, 0.000210652, 0.00012843, 7.82948e-05, 4.83376e-05, 2.99063e-05, 1.85995e-05, 1.16027e-05, 7.28539e-06]




    fig = figure(figsize=(5,4))
    ax = fig.add_subplot(1,1,1)
    plot(range(len(c095)), c095, '+', label='c=0.95')
    plot(range(len(c085)), c085, 'x', label='c=0.85')
    plot(range(len(c075)), c075, '2', label='c=0.75')
    plot(range(len(c065)), c065, '1', label='c=0.65')
    ax.set_yscale('log')
    ax.legend(prop={'size':10})
    ylabel('Residuo de norma 1 (log)')
    xlabel('# de iteraciones')
    fig.tight_layout()
    ax.set_ylim([1e-5 - 5e-6,1.])



    fig.savefig('convergencia-notredame.png')



def notredame_convergencia():
    c095 = [0.509119, 0.302075, 0.198991, 0.127336, 0.0839806, 0.0606219, 0.0480089, 0.0378658, 0.031487, 0.0265126, 0.0228915, 0.0200119, 0.017832, 0.0158883, 0.0143364, 0.0129636, 0.0117835, 0.0107435, 0.00985934, 0.00905446, 0.00834414, 0.00768855, 0.00709855, 0.00655922, 0.00607121, 0.00561827, 0.00520868, 0.00482965, 0.00448232, 0.00416337, 0.00387039, 0.00359784, 0.00334757, 0.00311561, 0.00290169, 0.00270469, 0.00252202, 0.0023519, 0.00219413, 0.00204755, 0.00191072, 0.00178394, 0.00166548, 0.00155537, 0.00145273, 0.00135734, 0.00126797, 0.00118527, 0.00110769, 0.00103561, 0.000968206, 0.000905496, 0.000846647, 0.000792107, 0.000740819, 0.000693202, 0.000648547, 0.000607005, 0.000567999, 0.000531821, 0.000497748, 0.000466116, 0.000436388, 0.000408719, 0.000382702, 0.000358579, 0.000335818, 0.000314701, 0.000294803, 0.000276305, 0.000258863, 0.000242689, 0.000227402, 0.000213219, 0.000199833, 0.000187395, 0.000175647, 0.000164752, 0.000154443, 0.000144884, 0.000135849, 0.000127466, 0.000119536, 0.000112184, 0.000105223, 9.87668e-05, 9.2656e-05, 8.69915e-05, 8.1627e-05, 7.66538e-05, 7.19399e-05, 6.75697e-05, 6.34274e-05, 5.95864e-05, 5.5946e-05, 5.25672e-05, 4.93619e-05, 4.63876e-05, 4.35651e-05, 4.09452e-05, 3.8459e-05, 3.61503e-05, 3.39592e-05, 3.19261e-05, 2.99974e-05, 2.82064e-05, 2.65064e-05, 2.49268e-05, 2.34275e-05, 2.20343e-05, 2.07117e-05, 1.94821e-05, 1.83147e-05, 1.72292e-05, 1.61987e-05, 1.52404e-05, 1.43305e-05, 1.3484e-05, 1.26804e-05, 1.19329e-05, 1.12231e-05, 1.0563e-05, 9.93633e-06]

    c085 = [0.455528, 0.241828, 0.142534, 0.0816079, 0.0481566, 0.0311029, 0.0220388, 0.0155528, 0.0115715, 0.00871778, 0.00673477, 0.00526785, 0.00419991, 0.0033482, 0.00270314, 0.00218701, 0.00177867, 0.00145098, 0.0011914, 0.000978969, 0.000807204, 0.00066549, 0.000549746, 0.000454506, 0.000376408, 0.00031166, 0.000258524, 0.000214479, 0.000178101, 0.000148015, 0.000123115, 0.000102398, 8.52463e-05, 7.09879e-05, 5.91544e-05, 4.93343e-05, 4.116e-05, 3.43432e-05, 2.86669e-05, 2.39358e-05, 1.9985e-05, 1.66949e-05, 1.39456e-05, 1.16528e-05, 9.73812e-06]

    c075 = [0.401936, 0.188274, 0.0979143, 0.0494654, 0.0257553, 0.0146776, 0.00917667, 0.0057141, 0.0037512, 0.00249361, 0.00169976, 0.00117312, 0.000825259, 0.000580502, 0.000413527, 0.000295208, 0.000211844, 0.000152483, 0.000110475, 8.00969e-05, 5.82737e-05, 4.2391e-05, 3.08984e-05, 2.25401e-05, 1.64709e-05, 1.20332e-05, 8.80733e-06]

    c065 = [0.348345, 0.141415, 0.0637386, 0.0279068, 0.012593, 0.00621968, 0.00337016, 0.00181871, 0.00103476, 0.000596143, 0.000352177, 0.000210652, 0.00012843, 7.82948e-05, 4.83376e-05, 2.99063e-05, 1.85995e-05, 1.16027e-05, 7.28539e-06]




    fig = figure(figsize=(5,4))
    ax = fig.add_subplot(1,1,1)
    plot(range(len(c095)), c095, '+', label='c=0.95')
    plot(range(len(c085)), c085, 'x', label='c=0.85')
    plot(range(len(c075)), c075, '2', label='c=0.75')
    plot(range(len(c065)), c065, '1', label='c=0.65')
    ax.set_yscale('log')
    ax.legend(prop={'size':10})
    ylabel('Residuo de norma 1 (log)')
    xlabel('# de iteraciones')
    fig.tight_layout()
    ax.set_ylim([1e-5 - 5e-6,1.])



    fig.savefig('convergencia-notredame.png')



notredame_convergencia()
