#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class Logger {
public:
	explicit Logger(ostream& output_stream) : os(output_stream) {
	}

	void SetLogLine(bool value) { log_line = value; }
	void SetLogFile(bool value) { log_file = value; }

	bool GetLogLine() const {
		return log_line;
	}

	bool GetLogFile() const
	{
		return log_file;
	}

	void Log(const string& message, const string& file, const int& line)
	{
		if (log_file && log_line)
		{
			os << file << ":" << line<< " " << message << std::endl;
		}
		else if (log_file)
		{
			os << file << " " << message << std::endl;
		}
		else if (log_line)
		{
			os << "Line " << line << " " << message << std::endl;
		}
		else
		{
			os << message << std::endl;
		}
		
	}

private:
	ostream& os;
	bool log_line = false;
	bool log_file = false;
};

#define LOG(logger, message) logger.Log(message, __FILE__, __LINE__)					
/*
int main()
{
	ostringstream logs;
	Logger l(logs);
	LOG(l, "hello");

	l.SetLogFile(true);
	LOG(l, "hello");

	l.SetLogLine(true);
	LOG(l, "hello");

	l.SetLogFile(false);
	LOG(l, "hello");

	return 0;
}*/