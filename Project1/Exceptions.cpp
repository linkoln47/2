#include "Exceptions.h"
#include "sstream"

Exceptions::Exceptions(int line, const char* file) noexcept
	:
	line (line),
	file (file)
{}

const char* Exceptions::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* Exceptions::GetType() const noexcept
{
	return "Exception";
}

int Exceptions::GetLine() const noexcept
{
	return line;
}

const std::string& Exceptions::GetFile() const noexcept
{
	return file;
}

std::string Exceptions::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}