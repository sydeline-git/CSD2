project(example2 VERSION 0.0.1)
juce_add_console_app(example2 PRODUCT_NAME "example2")
target_sources(example2 PRIVATE main.cpp osc.cpp sine.cpp saw.cpp square.cpp)
target_compile_definitions(example2 PRIVATE JUCE_WEB_BROWSER=0 JUCE_USE_CURL=0)

target_link_libraries(example2
        PRIVATE
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_processors

        PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_warning_flags
)

target_compile_features(example2 PRIVATE cxx_std_20)
