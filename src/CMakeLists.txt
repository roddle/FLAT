# determine architecture
if(CMAKE_SIZEOF_VOID_P EQUAL 8) 
    set(EXECUTABLE_NAME "FLAT.x86_64")
else() 
    set(EXECUTABLE_NAME "FLAT.x86")
endif() 

# change output exec file
set(EXECUTABLE_OUTPUT_PATH ../out/ CACHE PATH "Build directory" FORCE)

add_executable(${EXECUTABLE_NAME} main.cpp Game.cpp utilities.cpp StaticObject.cpp vec2.cpp vec3.cpp AudioManager.cpp BitmapBuffer.cpp Character.cpp DetailObject.cpp DragonHead.cpp DragonSpine.cpp DrawableBitmap.cpp DrawableCircle.cpp DrawableLine.cpp DrawableLine.cpp DrawableObject.cpp DrawableText.cpp DrawStack.cpp DrawStack3D.cpp Floor.cpp FrameContainer.cpp FrameSuperContainer.cpp GraphicsManager.cpp Pickup.cpp Player.cpp Projectile.cpp Splat.cpp Weapon.cpp)

target_link_libraries(${EXECUTABLE_NAME} allegro allegro_ttf allegro_audio allegro_acodec allegro_image allegro_main allegro_primitives allegro_font)

install( TARGETS ${EXECUTABLE_NAME}
         DESTINATION bin
         PERMISSIONS OWNER_READ OWNER_WRITE OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE )
