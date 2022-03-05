#pragma once
#include <mutex>
#include <functional>

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
        /**
         * @brief A function used to get and modify `T`
         * 
         * @param func A function that takes in a `T` reference
         * <p> The funtion then gets called with the `T` type
         * <p> In the function you would program what you wanted to do the `T`
         * <p> This is usefull if you need to get `T` in order to modify it or for any other reason
         */
        void processLocked(std::function<void(T&)> func) {
            std::lock_guard<std::mutex> lock(m_mutex);
            func(m_data);
        }
        /**
         * @brief A function used to get and modify `T`
         * 
         * @param func A function that takes in a `T` reference
         * <p> The funtion then gets called with the `T` type
         * <p> In the function you would program what you wanted to do the `T`
         * <p> This is usefull if you need to get `T` in order to modify it or for any other reason
         */
        void processLocked(std::function<void(const T&)> func) const {
            std::lock_guard<std::mutex> lock(m_mutex);
            func(m_data);
        }
    private:
        mutable std::mutex m_mutex;
        T m_data;
};
