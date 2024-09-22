#pragma once
#include <fstream>
#include <iostream>
#include <chrono>
enum class LogLevel
{
    DEBUG,
    RELEASE
};

class Log
{
private:
    static std::ofstream m_out;
    static LogLevel m_logLevel;
public:
    static void SetLogLevel(LogLevel logLevel)
    {
        m_logLevel = logLevel;

    }
    static void SetLogPath(const std::string& path)
    {
        m_out.open(path);
    }
    static void Write(const std::string& msg)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
        {
            std::cerr << dt << msg << std::endl;

        }
        m_out<< dt <<msg<<std::endl;
        m_out.flush();
    }
    static void Info(const std::string& msg)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::RELEASE)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
    static void Debug(const std::string& msg)
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
    static void Error(const std::string& msg)
    {time_t now = time(0);
        char* dt = ctime(&now);
        if (m_logLevel == LogLevel::DEBUG)
            std::cerr<<dt<<msg<<std::endl;
        m_out<<dt<<msg<<std::endl;
        m_out.flush();
    }
};