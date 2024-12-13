project(synthsong VERSION 0.0.1)
juce_add_console_app(synthsong PRODUCT_NAME "synthsong")
target_sources(synthsong PRIVATE main.cpp osc.cpp sine.cpp saw.cpp square.cpp triangle.cpp)
target_compile_definitions(synthsong PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(synthsong
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(synthsong PRIVATE cxx_std_20)
