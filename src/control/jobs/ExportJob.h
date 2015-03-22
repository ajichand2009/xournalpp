/*
 * Xournal++
 *
 * An export job for the export dialog
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __EXPORTJOB_H__
#define __EXPORTJOB_H__

#include "BlockingJob.h"
#include "ExportFormtType.h"
#include <StringUtils.h>
#include <XournalType.h>

class ExportJob : public BlockingJob
{
public:
    ExportJob(Control* control, GList* selected, ExportFormtType type, int dpi,
              string folder, string filename);  //TODO path

protected:
    virtual ~ExportJob();

public:
    virtual void run();

private:
    bool createSurface(int id, double width, double height);
    bool freeSurface(int id);

private:
    XOJ_TYPE_ATTRIB;


    GList* selected;

    cairo_surface_t* surface;
    cairo_t* cr;

    int dpi;
    ExportFormtType type;
    string filename;
    string folder;
    string front, back;
};

#endif /* __EXPORTJOB_H__ */
