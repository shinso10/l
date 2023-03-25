import pygame

pygame.init()
#создай окно игры
window = pygame.display.set_mode((700,500))
pygame.display.set_caption('THE WITCHER 3 FREE EDITION')
background = pygame.transform.scale(pygame.image.load('background.png'), (700,500))
window.blit(background, (0,0))
pygame.display.update()

sprite1 = pygame.transform.scale(pygame.image.load('sprite1.png'), (100,100))
sprite2 = pygame.transform.scale(pygame.image.load('sprite2.png'), (100,100))

x1=100
y1=300

x2=300
y2=300

speed = 10

run = True
clock = pygame.time.Clock()
FPS = 60

while run:
    window.blit(background, (0,0))
    window.blit(sprite1, (x1,y1))
    window.blit(sprite2, (x2,y2))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            run = False

    keys_pressed = pygame.key.get_pressed()

    if keys_pressed[pygame.K_LEFT] and x1 > 5:
        x1 -= speed
    if keys_pressed[pygame.K_RIGHT] and x1 < 595:
        x1 += speed
    if keys_pressed[pygame.K_UP] and y1 > 5:
        y1 -= speed
    if keys_pressed[pygame.K_DOWN]  and y < 395:
        y += speed

    if keys_pressed[pygame.K_a] and x2 >5:
        x2-= speed
    if keys_pressed[pygame.K_d] and x2 < 595:
        x2+= speed
    if keys_pressed[pygame.K_w] and y2 > 5:
        y2 -= speed
    if keys_pressed[pygame.K_s] and y2 >395:
        y2 += speed

    pygame.display.update()
    clock.tick(FPS)
