<?php

class BowlFrameState
{
	const Playing = 0;
    const FrameOver = 1;
    const GameOver = 2;
}

class BowlFrame {
	protected $rolls = array(0,0,0);
	protected $currentRoll = 0;
	public $isLastFrame = false;
	protected $maxNumPins = 10;

	public function __construct($lastFrame) {
		$this->isLastFrame = $lastFrame;
	}

	public function isSpare() {
		return ($this->getTwoRollPoints() == $this->maxNumPins);
	}

	public function isStrike () {
		return ($this->rolls[0] == $this->maxNumPins);
	}

	public function getOneRollPoints() {
		return $this->rolls[0];
	}

	public function getTwoRollPoints() {
		return $this->rolls[0]+$this->rolls[1];
	}

	public function getThreeRollPoints() {
		return $this->rolls[0]+$this->rolls[1]+$this->rolls[2];
	}

	public function getPoints($nextFrame, $nextNextFrame){
		$total = $this->getThreeRollPoints();
		
		// only if NOT last frame
		//  if last frame total is already correct
		if(!$this->isLastFrame)
		{
			// is strike
			if( $this->isStrike() ) {
				// next frame exists
				if($nextFrame != null)
				{
					// is strike AND NOT last frame
					if( $nextFrame->isStrike() &&
					   !$nextFrame->isLastFrame) {

					   	// add strike
						$total += $this->maxNumPins;
						// add next roll if frame exists
						if($nextNextFrame != null)
						{
							$total += $nextNextFrame->getOneRollPoints();
						}
					} else {
						// if either last frame or not strike
						// add next two roll points
						$total += $nextFrame->getTwoRollPoints();
					}
				}
			}
			// if frame a spare then get next first roll, if next frame exists
			else if( $this->isSpare() ) {
				if($nextFrame != null)
				{
					$total += $nextFrame->getOneRollPoints();
				}
			}
		}

		return $total;
	}

	// return BowlFrameState::FrameOver if frame over
	// return BowlFrameState::GameOver if game over
	// return BowlFrameState::Playing in all other cases
	public function addRoll($roll) {
		$this->rolls[$this->currentRoll] = $roll;
		$this->currentRoll++;

		// if NOT last frame AND 
		//   current roll is 2 OR strike
		// -> next frame
		if( (!$this->isLastFrame) && 
			( ($this->currentRoll == 2) ||
			   $this->isStrike() ) )
		{
			return BowlFrameState::FrameOver;
		}
		// if IS last frame AND 
		//   shot was a zero OR
		//     (current roll is 2 AND 
		//        points from last two shots less then 10) OR
		//     current roll is 3
		// -> game over
		else if( $this->isLastFrame && 
			     ( ($roll == 0) || 
			       ( ($this->currentRoll == 2) &&
			         ($this->getThreeRollPoints() < $this->maxNumPins) ) ||
			       ( $this->currentRoll == 3 )
			     )
			   )
		{
			return BowlFrameState::GameOver;
		}

		return BowlFrameState::Playing;
	}

	public function printFrame()
	{
		if(!$this->isLastFrame)
		{
			if($this->isStrike())
			{
				echo " [X]<br/>\n";
			} else {
				if($this->rolls[0] == 0) echo "-";
				else echo $this->rolls[0];

				if($this->rolls[1] == 0) echo "[-]";
				else if($this->isSpare()) echo "[/]";
				else echo "[".$this->rolls[1]."]";

				echo "<br/>\n";
			}
		} else {
			for($i = 0; $i < 3; $i++)
			{
				if($this->rolls[$i] == 0) break;

				if($this->rolls[$i] == $this->maxNumPins) echo "[x]";
				else if(($i == 1) && $this->isSpare() ) echo "[/]";
				else echo "[".$this->rolls[$i]."]";
				
			}
			echo "<br/>\n";
		}
	}

};


class Bowl {
	protected $maxNumFrames = 10;
	protected $frames = array();
	protected $currentFrame = 0;
	protected $gameOver = false;

	public function __construct() {
		$this->frames = array_fill(0, $this->maxNumFrames, null);

		// add first frame
		$this->frames[$this->currentFrame] = new BowlFrame(false);
	}

	public function addRoll($roll) {
		
		if($this->gameOver){
			printf("Game is over you can't add more rolls.<br/>\n");
			return;
		}

		$result = $this->frames[$this->currentFrame]->addRoll($roll);

		printf("Frame %d: Rolled a %d<br/>\n", 1 + $this->currentFrame, $roll);
		$this->printScore();

		$this->currentRoll++;
		// frame over
		if( $result == BowlFrameState::FrameOver )
		{
			$this->currentFrame++;
			// pass true if last frame
			$this->frames[$this->currentFrame] = new BowlFrame( ($this->currentFrame == ($this->maxNumFrames-1) ) );
		}
		// game over
		else if( $result == BowlFrameState::GameOver )
		{
			$this->gameOver = true;
		}
	}

	public function printScore()
	{
		if($this->gameOver)
		{
			echo "GameOver!<br/>\n";
		}

		echo "<table border='1' width='50%'><tr>\n";

		for($i = 0; $i < $this->maxNumFrames; $i++)
		{
			echo "<td width='10%'>".($i+1)."</td>";
		}

		echo "</tr><tr>\n";
		for($i = 0; $i < $this->maxNumFrames; $i++)
		{
			echo "<td width='10%'>";
			if($this->frames[$i] != null) {
				$this->frames[$i]->printFrame();
			}
			echo "</td>";
		}

		echo "</tr><tr>\n";
		$total = 0;
		for($i = 0; $i < $this->maxNumFrames; $i++)
		{
			if($this->frames[$i] != null)
			{
				// get next and next next frame if exist, if not set to null
				$next     = (array_key_exists($i+1, $this->frames) ? $this->frames[$i+1] : null);
				$nextNext = (array_key_exists($i+2, $this->frames) ? $this->frames[$i+2] : null);

				$total += $this->frames[$i]->getPoints($next, $nextNext);
				echo "<td width='10%'>$total</td>";
			} else {
				echo "<td width='10%'>&nbsp;</td>";
			}
		}
		echo "</tr></table></br>\n";

	}
}

$bowl = new Bowl();

$bowl->addRoll(10);
$bowl->addRoll(7);
$bowl->addRoll(3);
$bowl->addRoll(9);
$bowl->addRoll(0);
$bowl->addRoll(10);
$bowl->addRoll(0);
$bowl->addRoll(8);
$bowl->addRoll(8);
$bowl->addRoll(2);
$bowl->addRoll(0);
$bowl->addRoll(6);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(8);
$bowl->addRoll(1);

/*
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
$bowl->addRoll(10);
*/

$bowl->printScore();

?>