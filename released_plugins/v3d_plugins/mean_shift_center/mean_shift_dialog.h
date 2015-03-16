#ifndef MEAN_SHIFT_DIALOG_H
#define MEAN_SHIFT_DIALOG_H

#include <QtGui>
#include <QDialog>
#include <QToolBar>
#include <QVBoxLayout>
#include <QToolButton>
#include <v3d_interface.h>
#include "basic_surf_objs.h"
#include "mean_shift_fun.h"

#define NAME_INWIN "Input_mean_shift_center"
#define NAME_OUTWIN "Output_mean_shift_center"

void convert2UINT8(unsigned short *pre1d, unsigned char *pPost, V3DLONG imsz);
void convert2UINT8(float *pre1d, unsigned char *pPost, V3DLONG imsz);

class mean_shift_dialog:public QDialog
{
    Q_OBJECT
public:
    mean_shift_dialog(V3DPluginCallback2 *cb);
    mean_shift_fun mean_shift_obj;
    void core();
    void create_sphere();

private:

    V3DPluginCallback2 *callback;
    v3dhandle curwin;
    V3DLONG sz_img[4];
    unsigned char *image1Dc_in;
    LandmarkList LList,LList_in,LList_new_center;
    vector<V3DLONG> poss_landmark;
    vector<float> mass_center;

};




#endif // MEAN_SHIFT_DIALOG_H