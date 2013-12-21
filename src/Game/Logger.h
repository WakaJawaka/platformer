#pragma once

#include <string>
#include <fstream>
#include <memory>

namespace pf
{
	class Logger
	{
	public:
		static Logger& getInstance()
		{
			static Logger instance;

			return instance;
		}

		virtual ~Logger()
		{
			if(_pStream)
			{
				_pStream->close();

				delete _pStream;
			}
		}

		void log(std::string msg)
		{
			if(_pStream)
			{
				(*_pStream) << msg << std::endl;
			}
		}

	private:
		Logger()
		{
			_pStream = new std::ofstream("log.txt");
		}

		Logger(const Logger&);

		void operator=(const Logger&);

		std::ofstream* _pStream;
	};
}