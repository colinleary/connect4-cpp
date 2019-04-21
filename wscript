# Connect4 wscript

top = '.'
out = 'out'

SOURCES='*.cpp'

GXXFLAGS=['-Wall']

import glob

def configure(conf):
    conf.load('compiler_cxx')

    if conf.env.CC_NAME == 'msvc':
        conf.env.MSVC_TARGETS = ['x86']
        conf.env.CXXFLAGS = ['-W4', '-EHsc', '-Zi', '-FS']
        conf.env.LINKFLAGS += ['/DEBUG']
    else:
        conf.env.CXXFLAGS = ['-Wall']

def options(opt):
    opt.load('compiler_cxx')

def build(bld):
    bld.env.SOURCES=glob.glob(SOURCES)
    bld.program(source=bld.env.SOURCES, target='connect4')
