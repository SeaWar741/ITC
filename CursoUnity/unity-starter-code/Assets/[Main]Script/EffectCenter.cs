using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Vehicles.Car;
using UnityEngine.Events;
public class EffectCenter : MonoBehaviour {
    
    public CarAudio playerAud;
    public CarAudio aiAud;
    public AudioSource BGAudio;
    public UnityEvent startEvent;
    public UnityEvent winEvent;
    public UnityEvent loseEvent;
    public UnityEvent tutorialEvent;
    public UnityEvent countDownEvent;
    public UnityEvent StartGameEvent;
    public UnityEvent WarningEvent;
    private AudioSource _audioS;
    float maxBGVolume = 0.8f;

	// Use this for initialization
	void Start () {
        _audioS = this.GetComponent<AudioSource>();
        startEvent.Invoke();
	}
	
	// Update is called once per frame
	void Update () {
	}

    public void PlayerWin()
    {
        winEvent.Invoke();
    }

    public void PlayerLose()
    {
        loseEvent.Invoke();
    }

    public void Tutorial() {
        tutorialEvent.Invoke();
    }

    public void CountDownSound() {
        print("cds");
        countDownEvent.Invoke();
    }

    public void StartGame() {
        StartGameEvent.Invoke();
    }

    public void Warning(float sec) {
        WarningEvent.Invoke();
    }

    public void JustPlayThis(AudioClip clip) {
        _audioS.clip = clip;
        _audioS.Play();
    }

    public void BGFadeOutAndPlay(AudioClip clip) {
        LeanTween.value(BGAudio.gameObject,v=> BGAudio.volume = v, maxBGVolume, 0, 0.25f).setOnComplete(
            () => {
                BGAudio.clip = clip;
                LeanTween.value(BGAudio.gameObject, v => BGAudio.volume = v, 0, maxBGVolume, 0.5f);
                BGAudio.Play();
            });
    }

    public void StopCurrentAction() {
        print("stopEf");
        playerAud.StopSoundEnd();
        aiAud.StopSoundEnd();
    }


}
