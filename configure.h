#ifndef _CONFIGURE_H_
#define _CONFIGURE_H_
/** Configure holds settings like source folder, header info, packet 830 and magazine priority.
 *  It could also hold data about the teletext server that the client should connect to.
 *  /// @todo Rewrite this as a singleton
 *
 */

#include <iostream>
#include <fstream>
#include <stdint.h>
#include <cstring>
#include <sys/stat.h>
#include <vector>
#include <algorithm>
#include <stdexcept>

#define CONFIGFILE "vbit.conf" // default config file name
#define MAXPATH 132

namespace ttx

{
class Configure
{
public:
	//Configure();
	/** Constructor can take overrides from the command line
	 */
	Configure(int argc=0, char** argv=NULL);
	~Configure();

	inline char* GetPageDirectory(){return _pageDir;};

	std::string GetHeaderTemplate(){return _headerTemplate;}
	bool GetRowAdaptive(){return _rowAdaptive;}
	std::string GetServiceStatusString(){return _serviceStatusString;}
	bool GetMultiplexedSignalFlag(){return _multiplexedSignalFlag;}
	uint16_t GetNetworkIdentificationCode(){return _NetworkIdentificationCode;}
	uint8_t GetInitialMag(){return _initialMag;}
	uint8_t GetInitialPage(){return _initialPage;}
	uint16_t GetInitialSubcode(){return _initialSubcode;}
	uint8_t GetSubtitleRepeats(){return _subtitleRepeats;}
	uint16_t GetCommandPort(){return _commandPort;}

private:
	int DirExists(char *path);

	int LoadConfigFile(std::string filename);

	// template string for generating header packets
	std::string _headerTemplate;
	
	uint16_t _commandPort;

	bool _rowAdaptive;

	// settings for generation of packet 8/30
	bool _multiplexedSignalFlag; 	// false indicates teletext is multiplexed with video, true means full frame teletext.
	uint8_t _initialMag;
	uint8_t _initialPage;
	uint16_t _initialSubcode;
	uint16_t _NetworkIdentificationCode;
	uint16_t _CountryNetworkIdentificationCode;
	std::string _serviceStatusString; /// 20 characters
	char _configFile[MAXPATH]; /// Configuration file name --config
	char _pageDir[MAXPATH]; /// Configuration file name --dir
	uint8_t _subtitleRepeats; /// Number of times a subtitle repeats (typically 1 or 2).
};

}

#endif
