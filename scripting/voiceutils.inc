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
* @param index      Client index
*
* @return           true if client is speaking, false otherwise
*/
native bool:VU_IsClientSpeaking(const index);

/*
* Mutes the player.
*
* @param index      Client index
*
* @noreturn
*/
native VU_MuteClient(const index, const receiverIndex);

/*
* Unmutes the player.
*
* @param index      Client index
*
* @noreturn
*/
native VU_UnmuteClient(const index, const receiverIndex);

/*
* Checks whether the player is muted at the moment.
*
* @param index      Client index
* @param receiverIndex      Receiver index
*
* @return           true if client is muted, false otherwise
*/
native bool:VU_IsClientMuted(const index, const receiverIndex);

/*
* Creates audio buffer
*
* @return           buffer id or Invalid_BUFFER on failure
*/
native VU_Buffer:VU_BufferCreate();
/*
* Pushes bytes to buffer
* @param index      Buffer index
* @param buffer      bytes
* @param bufferlen      length of array
*
* @return          nothing
*/
native VU_BufferPush(VU_Buffer:index, buffer[], bufferlen);
/*
* Deallocates buffer
* @param index      Buffer index
*
* @return          nothing
*/
native VU_BufferDel(VU_Buffer:index);
/*
* Creates empty sound
*
* @return          sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateEmpty();
/*
* Creates sound from file
* @param path      Path to audio
*
* @return          sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateFromFile(path[]);
/*
* Creates sound from buffer
* @param index      Buffer id
* @param format     audio format eg:wav,mp3
*
* @return          sound index or Invalid_Sound on failure
*/
native VU_Sound:VU_SoundCreateFromBuffer(VU_Buffer:index, format[]="");
/*
* Deallocates sound
* @param index      Sound id
*
* @return          nothing
*/
native VU_SoundDelete(VU_Sound:index);
/*
* Marks sound to autodelete after playback finishes
* @param index      Sound id
*
* @return          nothing
*/
native VU_SoundDeleteAuto(VU_Sound:index);
/*
* Pushes buffer to sound
* @param index      Sound id
* @param audio_index      Bufferid id
* @param format     audio format eg:wav,mp3
*
* @return          nothing
*/
native VU_SoundPushAudio(VU_Sound:index, VU_Buffer:audio_index, format[]="");
/*
* Pushes buffer to sound
* @param index      Sound id
* @param audio_index      Bufferid id
* @param format     audio format eg:wav,mp3
*
* @return          nothing
*/
native VU_SoundCheckAudio(VU_Sound:index, VU_Buffer:audio_index, format[]="");
/*
* Playback sound for given receiver (use 0 for all players)
* @param index      Player id that playback sound
* @param receiver_id Player thats will receive that sound
* @param sound_index sound index
*
* @return          nothing
*/
native VU_SoundPlay(index, receiver_id, VU_Sound:sound_index);
/*
* Pauses sound
* @param sound_index sound index
*
* @return          nothing
*/
native VU_SoundPause(receiver_id, VU_Sound:index);
/*
* Seeks track to given position
* @param index sound index
* @param pos position to seek into
* @param seek param
*
* @return          nothing
*/
native VU_SoundSeek(receiver_id, VU_Sound:index, Float:pos, seekParam:seek);
/*
* Tells where is sound playing now
*
* @param index sound index
* @return          Current position 
*/
native Float:VU_SoundTell(receiver_id, VU_Sound:index);
/*
* Return total sound length
*
* @param index sound index
* @return          Total sound length
*/
native Float:VU_SoundLength(VU_Sound:index);
/*
* Called when the sound is complete played
*
* @param index      Sound index
*
* @noreturn
*/
forward VU_OnSoundComplete(receiver_id, const VU_Sound:index);
/*
* Called when the player started talking.
*
* @param index      Client index
*
* @noreturn
*/
forward VU_OnStartSpeak(const index);

/*
* Called when the player stopped talking.
*
* @param index      Client index
*
* @noreturn
*/
forward VU_OnStopSpeak(const index);
/*
native VU_IsDenoised(const index);
native VU_SetDenoise(const index, bool:active);
*/