using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GrowShrinkAnimation : MonoBehaviour {

    public float sec = 0.5f;
    public float size = 1.05f;
    private Vector3 orignalScale;
    // Use this for initialization
    void Start () {
        orignalScale = this.transform.localScale;
        Grow();
    }

    private void OnDisable()
    {
        this.transform.localScale = orignalScale;
    }

    private void Grow()
    {
        LeanTween.scale(this.gameObject, orignalScale * size, sec).setOnComplete(Shirnk);
    }

    private void Shirnk()
    {
        LeanTween.scale(this.gameObject, orignalScale, sec).setOnComplete(Grow);
    }

    public void DisableAnimation() {
        LeanTween.cancel(this.gameObject);
        LeanTween.scale(this.gameObject, orignalScale, 0.1f);
    }

    public void EnableAnimation() {
        Grow();
    }
}
