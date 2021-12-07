#if defined _voiceutils_included
    #endinput
#endif
#define _voiceutils_included

#pragma reqlib voice_utils
#if !defined AMXMODX_NOAUTOLOAD
    #pragma loadlib voice_utils
#endif

/*
* Buffer handle
*/
enum VU_Buffer
{
    Invalid_BUFFER = 0
}

/*
* Sound handle
*/
enum VU_Sound
{
    Invalid_Sound = 0
}

enum seekParam
{
    seekHead,
    seekCurr,
    seekTail
};

/*
* Checks whether the player is talking at the moment.
*
* @param index          Client index
*
* @return               true if client is speaking, false otherwise
*/
native bool:VU_IsClientSpeaking(const index);

/*
* Mutes the player.
*
* @param index          Client index
* @param receiverIndex  Receiver index
*
* @noreturn
*/
native VU_MuteClient(const index, const receiverIndex);

/*
* Unmutes the player.
*
* @param index          Client index
* @param receiverIndex  Receiver index
*
* @noreturn
*/
native VU_UnmuteClient(const index, const receiverIndex);

/*
* Checks whether the player is muted at the moment.
*
* @param index          Client index
* @param receiverIndex  Receiver index
*
* @return               true if client is muted, false otherwise
*/
native bool:VU_IsClientMuted(const index, const receiverIndex);

/*
* Creates audio buffer
*
* @return               Buffer index or Invalid_BUFFER on failure
*/
native VU_Buffer:VU_BufferCreate();

/*
* Pushes bytes to buffer
*
* @param index          Buffer index
* @param buffer         Bytes
* @param bufferlen      Length of array
*
* @return               Nothing
*/
native VU_BufferPush(VU_Buffer:index, buffer[], bufferlen);

/*
* Deallocates buffer
* @param index          Buffer index
*
* @return               Nothing
*/
native VU_BufferDel(VU_Buffer:index);

/*
* Creates empty sound
*
* @return               Sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateEmpty();

/*
* Creates sound from file
*
* @param path           Path to audio
*
* @return               Sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateFromFile(path[]);

/*
* Creates sound from buffer
*
* @param index          Buffer index
* @param format         Audio format eg:wav,mp3
*
* @return               Sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateFromBuffer(VU_Buffer:index, format[]="");

/*
* Deallocates sound
*
* @param index          Sound index
*
* @return               Nothing
*/
native VU_SoundDelete(VU_Sound:index);

/*
* Marks sound to autodelete after playback finishes
*
* @param index          Sound index
*
* @return               Nothing
*/
native VU_SoundDeleteAuto(VU_Sound:index);

/*
* Pushes buffer to sound
*
* @param index          Sound index
* @param audio_index    Buffer index
* @param format         Audio format eg:wav,mp3
*
* @return               Nothing
*/
native VU_SoundPushAudio(VU_Sound:index, VU_Buffer:audio_index, format[]="");

/*
* Playback sound for given receiver (use 0 for all players)
*
* @param index          Player index that playback sound
* @param receiver_id    Player thats will receive that sound
* @param sound_index    Sound index
*
* @return               Nothing
*/
native VU_SoundPlay(index, receiver_id, VU_Sound:sound_index);

/*
* Pauses sound
*
* @param sound_index    Sound index
*
* @return               Nothing
*/
native VU_SoundPause(VU_Sound:index);

/*
* Seeks track to given position
*
* @param index          Sound index
* @param pos            Position to seek into
* @param seek           enum seekParam
*
* @return               Nothing
*/
native VU_SoundSeek(VU_Sound:index, Float:pos, seekParam:seek);

/*
* Tells where is sound playing now
*
* @param index          Sound index
*
* @return               Current position
*/
native Float:VU_SoundTell(VU_Sound:index);

/*
* Return total sound length
*
* @param index          Sound index
*
* @return               Total sound length
*/
native Float:VU_SoundLength(VU_Sound:index);

/*
* Called when the sound is complete played
*
* @param index          Sound index
*
* @noreturn
*/
forward VU_OnSoundComplete(const VU_Sound:index);

/*
* Called when the player started talking.
*
* @param index          Client index
*
* @noreturn
*/
forward VU_OnStartSpeak(const index);

/*
* Called when the player stopped talking.
*
* @param index          Client index
*
* @noreturn
*/
forward VU_OnStopSpeak(const index);

/*
native VU_IsDenoised(const index);
native VU_SetDenoise(const index, bool:active);
*/
