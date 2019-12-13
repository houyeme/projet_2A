QT       += core gui sql
QT       += core gui
QT       += core gui multimedia multimediawidgets
QT       += core gui printsupport
QT       += core gui network sql printsupport serialport charts \
            multimedia multimediawidgets


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin_panal.cpp \
    ambulance.cpp \
    appel_urgence.cpp \
    arduino.cpp \
    cadmin.cpp \
    chauffeur.cpp \
    connexion.cpp \
    contrat.cpp \
    equipement.cpp \
    equipement_paramedicale.cpp \
    fournisseur.cpp \
    gerer_umbulance.cpp \
    gestion_de_mediacament.cpp \
    gestion_de_mediacament1.cpp \
    gestion_des_patients.cpp \
    gestion_equipement.cpp \
    main.cpp \
    mainwindow.cpp \
    medecin.cpp \
    medicament.cpp \
    notifcation.cpp \
    patient.cpp \
    personnel.cpp \
    pharmacien.cpp \
    qcustomplot.cpp \
    rendez_vous.cpp \
    responsable.cpp \
    secretaire.cpp \
    smtp.cpp \
    src/emailaddress.cpp \
    src/mimeattachment.cpp \
    src/mimecontentformatter.cpp \
    src/mimefile.cpp \
    src/mimehtml.cpp \
    src/mimeinlinefile.cpp \
    src/mimemessage.cpp \
    src/mimemultipart.cpp \
    src/mimepart.cpp \
    src/mimetext.cpp \
    src/quotedprintable.cpp \
    src/smtpclient.cpp \
    statistique.cpp \
    statistiques.cpp

HEADERS += \
    admin_panal.h \
    ambulance.h \
    appel_urgence.h \
    arduino.h \
    cadmin.h \
    chauffeur.h \
    connexion.h \
    contrat.h \
    equipement.h \
    equipement_paramedicale.h \
    fournisseur.h \
    gerer_umbulance.h \
    gestion_de_mediacament.h \
    gestion_de_mediacament1.h \
    gestion_des_patients.h \
    gestion_equipement.h \
    mainwindow.h \
    medecin.h \
    medicament.h \
    notifcation.h \
    patient.h \
    personnel.h \
    pharmacien.h \
    qcustomplot.h \
    rendez_vous.h \
    responsable.h \
    secretaire.h \
    smtp.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    statistique.h \
    statistiques.h

FORMS += \
    admin_panal.ui \
    gerer_umbulance.ui \
    gestion_de_mediacament.ui \
    gestion_de_mediacament1.ui \
    gestion_des_patients.ui \
    gestion_equipement.ui \
    mainwindow.ui \
    statistique.ui \
    statistiques.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    image.qrc \
    ressource.qrc

DISTFILES += \
    ../../../Downloads/medicament/medicament/True Detective - Intro Opening Song - Theme (The Handsome Family - Far From Any Road) + LYRICS.mp3

SUBDIRS += \
    ../../../Downloads/medicament/medicament/medicament.pro \
    medicament.pro
