using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityStandardAssets.Vehicles.Car;
using UnityStandardAssets.Utility;
using UnityEngine.SceneManagement;

public class GameCondition : MonoBehaviour {

    public int countDownSecond = 5;
    public float warningAng = 110;
    public CarUserControl playerController;
    public CarAIControl aiController;
    public UIControl myUiControl;
    public WaypointCircuit wayCircuit;
    public WayPointTriggerBox endTrigger;
    public WayPointTriggerBox midTrigger;
    public EffectCenter myEffect;

    [HideInInspector]
    public Vector3 nextGoal = Vector3.zero;
    private Transform playerTrans;
    private bool warning = false;
    private float warningSec = 1.5f;
    private int wayPointCount = 1;
    private Transform[] Waypoints;
    private Coroutine CountDownRoutine;
    private Coroutine CheckRoutine;

    // Use this for initialization
    void Start () {
        midTrigger._gameCon = endTrigger._gameCon = this;
        playerTrans = playerController.gameObject.transform;
        GoalSetting();
    }
	
	// Update is called once per frame
	void Update () {
           
    }

    public void UpdateNextGoal() {
        if (wayPointCount < Waypoints.Length) {
            nextGoal = Waypoints[wayPointCount].position;
            Waypoints[wayPointCount].gameObject.GetComponent<BoxCollider>().enabled = true;

            wayPointCount++;
        }
    }

    private void GoalSetting() {
        Waypoints = wayCircuit.Waypoints;
        UpdateNextGoal();
    }

    private bool NeedToSetWarning() {
        Vector3 playerToNextGoalVector = nextGoal - playerTrans.position;
        Debug.DrawRay(playerTrans.position,nextGoal,Color.red);
        float ang = Vector3.Angle(playerToNextGoalVector, playerTrans.forward);
        //print(ang);
        return ang>warningAng
            && nextGoal != Vector3.zero
            && !warning;
    }

    public void MidTrigger() {
        endTrigger.EnableCollider();
    }

    public void EndGameTrigger(bool iWon) {

        SetAIandPlayer(false);

        if (iWon) {
            PlayerWin();
        } else {
            PlayerLose();
        }
    }

    private void PlayerWin() {
        print("I win");
        StopCoroutine(CheckRoutine);
        myUiControl.StopCurrentAction();
        myEffect.StopCurrentAction();
        myUiControl.PlayerWin();
        myEffect.PlayerWin();
    }

    private void PlayerLose() {
        print("I lose");
        StopCoroutine(CheckRoutine);
        myUiControl.StopCurrentAction();
        myEffect.StopCurrentAction();
        myUiControl.PlayerLose();
        myEffect.PlayerLose();
    }

    private void SetAIandPlayer(bool sit) {
        playerController.enabled = sit;
        if (sit){
            aiController.m_Driving =
            aiController.enabled = true;
        } else {
            aiController.m_Driving = false;
            LeanTween.delayedCall(0.5f,
            () => { aiController.enabled = false; });
        } 
    }

    public void Restart() {
        SceneManager.LoadScene(0);
    }

    public void SetWarning() {
        warning = true;
        LeanTween.delayedCall(warningSec*1.1f, () =>
        {
            warning = false;
        });
        myUiControl.Warning(warningSec);
        myEffect.Warning(warningSec);

    }

    public void StartTutorial() {
        myEffect.Tutorial();
        myUiControl.OpenTutorial();
    }

    public void StartCountingDown() {
        myUiControl.CloseTutorial();
        CountDownRoutine = StartCoroutine(CountingDown());
        CheckRoutine = StartCoroutine(CheckDirection());
    }

    IEnumerator CheckDirection() {
        while (true) {
            yield return new WaitForSeconds(0.5f);
            if (NeedToSetWarning())
            {
                SetWarning();
            }
        }
    }

    IEnumerator CountingDown()
    {
        yield return new WaitForSeconds(0.6f);
        myUiControl.StartCountDown(countDownSecond);
        myEffect.CountDownSound();

        while (countDownSecond > 0)
        {
            yield return new WaitForSeconds(1);
            countDownSecond--;
            myUiControl.CountDown(countDownSecond);
            myEffect.CountDownSound();
        }

        myEffect.StartGame();
        SetAIandPlayer(true);
        StopCoroutine(CountDownRoutine);
    }
}
