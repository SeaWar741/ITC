using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ClickToStart : MonoBehaviour {

    
    public GameCondition _gameCon;
    private Vector3 orignalScale;

	// Use this for initialization
	void Start () {
        orignalScale = this.transform.localScale;
    }
	
	// Update is called once per frame
	void Update () {
        if (Input.GetMouseButtonUp(0) || Input.anyKeyDown) {
            _gameCon.StartTutorial();
            LeanTween.cancel(this.gameObject);
            LeanTween.scale(this.gameObject, orignalScale * .05f, 0.5f).setEaseOutExpo().setOnComplete(
                ()=> { this.gameObject.SetActive(false); }
                );
            this.enabled = false;
        }
	}

}
