#ifndef _FILEMONITOR_H_
#define _FILEMONITOR_H_

#include <iostream>
#include <thread>
#include <list>
#include <sys/stat.h>

#include "configure.h"
#include "pagelist.h"


/**
 * @brief Watches for changes to teletext page files and updates the page list as needed
 * www.ibm.com/developerworks/linux/library/l-ubuntu-inotify/index.html
 */

namespace vbit
{

class FileMonitor
{
  public:
    /** Default constructor */
    FileMonitor();
    FileMonitor(ttx::Configure *configure, ttx::PageList *pageList);
    /** Default destructor */
    virtual ~FileMonitor();

	/**
	 * Runs the monitoring thread and does not terminate (at least for now)
	 * @return Nothing useful yet. Perhaps return an error status if something goes wrong
	 */
	 void run();

  protected:

  private:
    ttx::Configure* _configure; /// Member reference to the configuration settings
    ttx::PageList* _pageList;

};

}

#endif // _FILEMONITOR_H_
