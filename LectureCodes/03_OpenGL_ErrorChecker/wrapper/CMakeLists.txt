#递归遍历将本文件夹下所以cpp放入FUNCS中
file(GLOB_RECURSE WRAPPER ./ *.CPP)

#将FUNCS中所有cpp编译为funcs这个lib库
add_library(wrapper ${WRAPPER})	