using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WayPointTriggerBox : MonoBehaviour {

    public BoxType myType;
    [HideInInspector]
    public GameCondition _gameCon;
    [HideInInspector]
    public BoxCollider _myCol;

    public enum BoxType {Normal,Mid,End };

    // Use this for initialization
    void Start () {
        _myCol = this.GetComponent<BoxCollider>();
        if (myType == BoxType.End) _myCol.enabled = false;
        if (_gameCon == null) _gameCon = GameObject.FindGameObjectWithTag("ControlCenter").GetComponent<GameCondition>();
    }
	
	// Update is called once per frame
	void Update () {
		
	}

    public void EnableCollider()
    {
        _myCol.enabled = true;
    }

    private void TriggerMidBox(Collider other) {
        if (other.tag == "MyCar" || other.tag == "Car")
        {
            _gameCon.MidTrigger();
            _myCol.enabled = false;
        }
    }

    private void TriggerEndBox(Collider other) {
        if (other.tag == "MyCar")
        {
            _gameCon.EndGameTrigger(true);
            _myCol.enabled = false;
            this.enabled = false;
        }

        if (other.tag == "Car")
        {
            _gameCon.EndGameTrigger(false);
            _myCol.enabled = false;
            this.enabled = false;
        }
    }


    private void TriggerNormalBox(Collider other) {
        if (other.tag == "MyCar")
        {
            _gameCon.UpdateNextGoal();
            _myCol.enabled = false;
        }
    }

    public void OnTriggerEnter(Collider other)
    {
        switch (myType) {
            case BoxType.Mid:
                TriggerMidBox(other);
                break;
            case BoxType.End:
                TriggerEndBox(other);
                break;
            default:
                TriggerNormalBox(other);
                break;
        }
    }
}
