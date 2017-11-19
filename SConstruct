import os 


env = Environment()

env.VariantDir('build', 'src', duplicate=0)

subdir = ['build/SConscript']

env.SConscript(subdir, 'env')

Export('env')
