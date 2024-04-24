import os 

with open('temp.csi', 'r') as file:
        code = file.read()
code = list(reversed(code.split('\n')))
print('\n'.join(code))