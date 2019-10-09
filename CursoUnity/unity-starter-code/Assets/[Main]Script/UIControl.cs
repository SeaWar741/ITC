using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UIControl : MonoBehaviour {

    
    public Text countDownText;
    public GameObject winScreen;
    public GameObject loseScreen;
    public GameObject warning;
    
    public GameObject welcomeTitle;
    public GameObject tutorialUI;
    public GameObject restartButton;
    public GameObject tutorialButton;
    public GameObject miniMap;

    private Vector3 originalCountDownTextSize;
    private float restartButtonShowSecond = 2;

	// Use this for initialization
	void Start () {
        originalCountDownTextSize = countDownText.transform.localScale;

    }
	
	// Update is called once per frame
	void Update () {
		
	}
    public void StartCountDown(int sec) {
        Vector3 miniMapOrg = miniMap.transform.localScale;
        miniMap.transform.localScale *= 0.1f;
        miniMap.SetActive(true);
        LeanTween.scale(miniMap, miniMapOrg, 0.5f).setEaseOutExpo();
        countDownText.enabled = true;
        CountDown(sec);
    }

    public void CountDown(int sec) {
        if (sec == 0)
        {
            countDownText.text = "Start!";
            LeanTween.delayedCall(1f, () => { countDownText.enabled = false; });
        }
        else {
            countDownText.text = sec.ToString();
        }
        countDownText.transform.localScale = originalCountDownTextSize;
        LeanTween.scale(countDownText.gameObject, originalCountDownTextSize * 0.01f, 0.9f).setEaseInOutExpo();

    }

    public void PlayerWin() {

        winScreen.SetActive(true);
        LeanTween.scale(miniMap, Vector3.zero, 0.5f).setEaseOutExpo();
        LeanTween.delayedCall(0.5f,()=> {
            miniMap.SetActive(false);
        });
        LeanTween.delayedCall(restartButtonShowSecond, () => {
            restartButton.SetActive(true);
        });
    }

    public void PlayerLose() {

        loseScreen.SetActive(true);
        LeanTween.scale(miniMap, Vector3.zero, 0.5f).setEaseOutExpo();
        LeanTween.delayedCall(0.5f, () => {
            miniMap.SetActive(false);
        });

        LeanTween.delayedCall(restartButtonShowSecond, () => {
            restartButton.SetActive(true);
        });
    }

    public void OpenTutorial() {
        welcomeTitle.gameObject.SetActive(false);
        tutorialUI.SetActive(true);
        Vector3 org = tutorialUI.transform.localScale;
        tutorialUI.transform.localScale *= .01f;
        LeanTween.scale(tutorialUI.gameObject, org, 0.5f).setEaseOutExpo();
        LeanTween.delayedCall(1f, () =>
        {
            Vector3 orgS = tutorialButton.transform.localScale;
            tutorialButton.transform.localScale *= .1f;
            tutorialButton.SetActive(true);
            LeanTween.scale(tutorialButton, orgS, 0.5f).setEaseOutExpo().setOnComplete(
            () => {
                tutorialButton.GetComponent<GrowShrinkAnimation>().enabled = true; }
                );
            
        });
    }

    public void CloseTutorial() {
        LeanTween.scale(tutorialUI.gameObject,
            tutorialUI.transform.localScale * .01f, .5f).setEaseOutExpo().setOnComplete(
            ()=> { tutorialUI.SetActive(false); });
    }

    public void StopCurrentAction() {
        warning.SetActive(false); ;
    }

    public void Warning(float sec) {
        GrowShrinkAnimation _ani = warning.gameObject.GetComponent<GrowShrinkAnimation>();
        _ani.sec = sec / 4;
        _ani.enabled = true;
        warning.SetActive(true);
        LeanTween.delayedCall(sec, () => {
            _ani.enabled =  false;
            warning.SetActive(false);
        });
    }

}
