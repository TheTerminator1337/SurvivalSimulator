#pragma once

#include "Entity.hpp"
#include "Inventory.hpp"
#include "ExamineMenu.hpp"
#include "Camera.hpp"
#include "Console.hpp"

class Player : public Entity
{
public:
	Player(sf::RenderWindow& context);

	void init();

	static const sf::Vector2f& getPos() { return m_sprite.getPosition(); }

	Inventory& getInventory() { return m_inventory; }
	Camera& getCamera() { return m_camera; }
	ItemManager& getItemManager() { return m_itemManager; }

	static Console& getConsole() { return m_console; }

	void addItem(ItemManager::Item::Ptr item);

	bool getActive() { return m_active; }
	void setActive(bool active) { m_active = active; if (!active) m_inventory.setActive(active); }

	const float getStamina() const { return m_stamina; }

	int checkDistanceTileRef();

	void handleEvents(const sf::Event& event);

	virtual bool nextPosValid(const sf::Vector2f& offset, World& world);

	virtual void update(sf::Time dt, thor::ActionMap<Keys::KeyboardInput>& keys, World& world);
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	//Event methods that are binded to specific buttons
public:
	void onCollectPress(ActionManager& actionManager, Action::Ptr itemActionContext);
	void onPickupPress(World& world);

private:
	void updateMovement(sf::Time dt, thor::ActionMap<Keys::KeyboardInput>& keys, World& world);
	void updateInput(sf::Time dt, thor::ActionMap<Keys::KeyboardInput>& keys, World& world);

	bool checkCollisions(sf::FloatRect& rect, World& world);

private:
	static sf::Sprite m_sprite;
	sf::Texture m_animationSteps;
	sf::Image m_image;

	sf::RenderWindow* m_windowContext;

	Inventory m_inventory;
	ExamineMenu m_examineMenu;
	ItemManager m_itemManager;

	static Console m_console;

	float m_walkSpeed;
	float m_sprintSpeed;

	float m_stamina;
	float m_health;
	float m_thirst;
	float m_encumbrance;

	float m_requiredStaminaToSprint;

	sf::Vector2f m_defaultCameraPos;
	bool m_keepUpdatingCameraX, m_keepUpdatingCameraY;

	int runCounter;

	//Per second
	float m_baseStaminaDegen;
	float m_baseStaminaRegen;

	float m_inventoryWeight;

	bool m_active;

	bool m_isSprinting;
	bool m_isWalking;

	bool m_isCurrentlyMoving;

	Camera m_camera;

	TileMap::TileEntityRef::Ptr m_entityRef; //The tile the player currently clicked

	ItemManager::Item::Ptr m_itemRef; //The item the player currently clicked
	std::string m_itemRefId;
};