#pragma once
#include <mutex>

/**
 * @brief This data will be thread safe using this class
 * <p> This can be used if you want to get data from one thread to another
 * 
 * @tparam T 
 */
template<typename T>
class SafeData {
    public:
        /**
         * @brief Sets the data to be read by another thread
         * 
         * @param data The data
         */
        void set(T data) {
            std::lock_guard<std::mutex> lock(m_mutex);
            m_data = data;
        }
        /**
         * @brief Returns the data
         * 
         * @return T The data type
         */
        T get() {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_data;
        }
    private:
        std::mutex m_mutex;
        T m_data;
};
