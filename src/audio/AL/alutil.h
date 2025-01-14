#ifndef SRC_AUDIO_AUDIOUTIL_H_
#define SRC_AUDIO_AUDIOUTIL_H_

#include <string>
#include <type_traits>
#include <cstdint>

#ifdef __APPLE__
#include <OpenAL/al.h>
#else
#include <AL/al.h>
#endif

#include <glm/glm.hpp>
#include "../../typedefs.h"

#define AL_CHECK(STATEMENT) STATEMENT; AL::check_errors(__FILE__, __LINE__)
#define AL_GET_ERROR() AL::check_errors(__FILE__, __LINE__)

namespace AL {
    bool check_errors(const std::string& filename, const std::uint_fast32_t line);

    /// @brief alGetSourcef wrapper
    /// @param source target source
    /// @param field enum value
    /// @param def default value will be returned in case of error
    /// @return field value or default
    inline float getSourcef(uint source, ALenum field, float def=0.0f) {
        float value = def;
        AL_CHECK(alGetSourcef(source, field, &value));
        return value;
    }

    /// @brief alGetSource3f wrapper
    /// @param source target source
    /// @param field enum value
    /// @param def default value will be returned in case of error
    /// @return field value or default
    inline glm::vec3 getSource3f(uint source, ALenum field, glm::vec3 def={}) {
        glm::vec3 value = def;
        AL_CHECK(alGetSource3f(source, field, &value.x, &value.y, &value.z));
        return value;
    }

    /// @brief alGetSourcei wrapper
    /// @param source target source
    /// @param field enum value
    /// @param def default value will be returned in case of error
    /// @return field value or default
    inline float getSourcei(uint source, ALenum field, int def=0) {
        int value = def;
        AL_CHECK(alGetSourcei(source, field, &value));
        return value;
    }

    static inline ALenum to_al_format(short channels, short bitsPerSample){
        bool stereo = (channels > 1);

        switch (bitsPerSample) {
        case 16:
            if (stereo)
                return AL_FORMAT_STEREO16;
            else
                return AL_FORMAT_MONO16;
        case 8:
            if (stereo)
                return AL_FORMAT_STEREO8;
            else
                return AL_FORMAT_MONO8;
        default:
            return -1;
        }
    }
}

#endif /* SRC_AUDIO_AUDIOUTIL_H_ */
