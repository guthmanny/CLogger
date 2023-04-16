#ifndef __CLogger__H__
#define __CLogger__H__
#include <fstream>
#include <iostream>
#include <cstdarg>
#include <string>

#define LOGGER CLogger::Get Logger()

/**
* Singleton Logger Class.
*/

class CLogger
{
public:
	/**
	*	Logs a message
	*	@param sMessage message to be logged.
	*/
	void Log(const std::string& sMessage);
	
	/**
	*	Variable Length Logger Function
	*	@Param format string for the message to be logged.
	*/
	void Log(const char* format, ...);
	
	/**
	*	<< overloaded function to logs a message
	*	@param sMessage message to be logged.
	*/
	CLogger& operator<<(const std::string& sMessage);
	/**
	*	Function to create the instance of logger class.
	*	@return singleton object of CLogger class..
	*/
	static CLogger* GetLogger();
private:
	/**
	*	Default constructor for the logger class.
	*/
	CLogger();
	/**
	*	Log file name.
	**/
	static const std::string m_sFileName;
	/**
	*	Singleton logger class object pointer.
	**/
	static CLogger* m_pThis;
	/**
	*	Log file stream object.
	**/
	static std::ofstream m_Logfile;
};

#endif
