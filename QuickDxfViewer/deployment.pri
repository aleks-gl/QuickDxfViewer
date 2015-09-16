android-no-sdk {
    target.path = /data/user/qt
    export(target.path)
    INSTALLS += target
} else:android {
    x86 {
        target.path = /libs/x86
    } else: armeabi-v7a {
        target.path = /libs/armeabi-v7a
    } else {
        target.path = /libs/armeabi
    }
    export(target.path)
    INSTALLS += target
} else:unix {
    isEmpty(target.path) {
        qnx {
            target.path = /tmp/$${TARGET}/bin
        } else {
            target.path = /opt/$${TARGET}/bin
        }
        export(target.path)
    }
    INSTALLS += target
}
greaterThan( QT_MAJOR_VERSION, 4) {
        CONFIG += c++11
}else{
        QMAKE_CXXFLAGS += -std=c++11
        QMAKE_CXXFLAGS_DEBUG += -std=c++11
}

macx{
    QMAKE_CXXFLAGS_DEBUG += -mmacosx-version-min=10.8
    QMAKE_CXXFLAGS += -mmacosx-version-min=10.8
}
export(INSTALLS)
