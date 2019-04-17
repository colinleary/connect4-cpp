# Connect4 wscript

from waflib import Utils

top = '.'
out = 'out'

SOURCES='*.cpp'
MSVCFLAGS=['-W4', '-EHsc', '-Zi', '-FS']
MSVCLFLAGS=['/DEBUG']
GXXFLAGS=['-Wall']
LIBS=[]

import glob

def configure(conf):
    if Utils.is_win32:
        conf.env.MSVC_TARGETS=['x86']
        conf.env.CXXFLAGS=MSVCFLAGS
        conf.env.LINKFLAGS += MSVCLFLAGS
    else:
        conf.env.CXXFLAGS=GXXFLAGS

    conf.load('compiler_cxx')
    conf.env.SOURCES=glob.glob(SOURCES)

def options(opt):
    opt.load('compiler_cxx')

def build(bld):
    bld.program(source=bld.env.SOURCES, target='connect4')
